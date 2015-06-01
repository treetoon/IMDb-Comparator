#include <string>
#include <iostream>

#include "TitleList.h"
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
	if (fin){
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

std::string TitleList::getTitleVar(unsigned int titlePos, unsigned int titleVarPos)
{
	if (titlePos <= title.size() && titlePos >= 0 && !title.empty() && 
		titleVarPos <= imdb::TOT_TITLE_VARS && titleVarPos >= 0)
	{
		return title.at(titlePos).getTitleVars(titleVarPos);
	}
	else{
		return "";
	}
}

void TitleList::setTitleVar(unsigned int titlePos, unsigned int titleVarPos, std::string name)
{
	if (titlePos <= title.size() && titlePos >= 0 && !title.empty() &&
		titleVarPos <= imdb::TOT_TITLE_VARS && titleVarPos >= 0)
	{
		title.at(titlePos).setTitleVars(titleVarPos, name);
	}
}

void TitleList::addTitleEntry(Title titleEntry)
{
	title.push_back(titleEntry);
}

void TitleList::removeTitleEntry(unsigned int titleEntryPos)
{
	//title.erase(title.begin() + titleEntryPos);
	title[titleEntryPos].setTitleVars(0, "");
}

Title TitleList::getTitleEntry(unsigned int titleEntryPos)
{
	return title.at(titleEntryPos);
}