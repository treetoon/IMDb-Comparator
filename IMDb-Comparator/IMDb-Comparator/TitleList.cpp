//Standard Library
#include <string>
#include <windows.h>

//non-Standard Library
#include <dirent.h>

//Header
#include "titlelist.h"

//Definitions
#include "imdb_defines.h"


TitleList::TitleList() : title(0)
{
	autoReadFiles();
}


TitleList::~TitleList()
{
}

bool TitleList::writeFile(std::ostream &out)
{
	//write all vector titles to a file

	if (out){
		for (size_t i = 0; i < title.size(); i++)
		{
			title[i].writeTitle(out);
		}
		return true;
	}
	return false;
}

bool TitleList::readFile(std::istream &fin)
{
	//clear the film title vector
	title.clear();

	//adds titles from file to array
	if (fin)
	{
		//check for the example film entry row in the file
		removeFilmEntryExample(fin);

		while (!fin.eof())
		{
			Title temp;
			if (temp.readTitle(fin)){
				title.push_back(temp); //add element at end
			}
		}
		return true;
	}
	return false;
}

std::string *TitleList::autoReadFiles()
//check if there is a base folder with .csv files, then try to find two
{
	const unsigned int PATHS_MAX = 2;
	static std::string fullPaths[PATHS_MAX];
	std::string path;

	//search current directory to store the path to the exe
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);

	//remove our application (exe) from the path
	std::string::size_type pos = std::string(buffer).find_last_of("\\");
	path = std::string(buffer).substr(0, pos);

	//add the base folder to the path
	DIR *dir = opendir(path.append(BASEPATH).c_str());

	fullPaths[0] = path;
	fullPaths[1] = path;

	dirent *ent;
	std::string filename; 
	unsigned int apos = 0;

	if (dir != NULL){ //success
		while ((ent = readdir(dir)) != NULL && apos != PATHS_MAX) //loop through the files in base directory
		{
			filename = ent->d_name; //get the filenames

			//if .csv can be found at the end of the filename, we assume we can read it
			if (filename.size() >= 4){
				if (filename.compare(filename.size() - 4, 4, ".csv") == NULL)
				{
					fullPaths[apos].append("\\" + filename); //we now have a full path to the .csv file
					apos++;
				}
			}
		}
	closedir(dir);
	}
	
	//reverse slashes in the path URL (Encode/Decode)
	for (int x = 0; x < PATHS_MAX; x++){
		int i = 0;
		while (fullPaths[x][i] != '\0')
		{
			if (fullPaths[x][i] == '\\')
				fullPaths[x][i] = '/';
			i++;
		}
	}

	//determine what to return dependant on how many files we found
	switch (apos)
	{
	case 0: //no .csv file found
		fullPaths[0].clear();
		fullPaths[1].clear();
		return fullPaths;
		break;
	case 1: //one
		fullPaths[1].clear();
		return fullPaths;
		break;
	case 2: //two
		return fullPaths;
		break;
	default:
		return fullPaths;
		break;
	}
}

int TitleList::getSizeOfVector()
{
	return title.size();
}

bool TitleList::removeFilmEntryExample(std::istream &fin)
//checks if the first entry in the TitleList (.csv file) is considered an 
//example, i.e, looking like this: "position","const","created".. etc 
{
	if (fin)
	{
		Title temp;

		if (temp.readTitle(fin))
		{
			if (temp.getTitleVar(imdb::CONSTID) == "const"){
				return true; //film entry example was found, don't read it in
			}
			else{
				title.push_back(temp); //film entry example was not found, read it in
				return false;
			}
		}
	}
	return false;
}

std::string TitleList::getTitleVar(int titlePos, int titleVarPos)
{
	if (titlePos < title.size() && titlePos >= 0 && !title.empty() && 
		titleVarPos < imdb::TOT_TITLE_VARS && titleVarPos >= 0)
	{
		return title.at(titlePos).getTitleVar(titleVarPos);
	}
	else{
		return "EXIT_FAILURE";
	}
}

void TitleList::setTitleVar(int titlePos, int titleVarPos, std::string name)
{
	if (titlePos < title.size() && titlePos >= 0 && !title.empty() &&
		titleVarPos < imdb::TOT_TITLE_VARS && titleVarPos >= 0)
	{
		title.at(titlePos).setTitleVars(titleVarPos, name);
	}
}

void TitleList::addTitleEntry(Title titleEntry)
{
	title.push_back(titleEntry);
}

Title TitleList::getTitleEntry(int titleEntryPos)
{
	return title.at(titleEntryPos);
}
