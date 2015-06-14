#include <string>
#include <iostream>
#include <vector> //?
#include <algorithm> //?

#include "titlelist.h"
#include "imdb_defines.h"


TitleList::TitleList() : title(0)
{
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
