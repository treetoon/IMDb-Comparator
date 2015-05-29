#include <string>
#include <iostream>

#include "TitleList.h"
#include "imdb_constants.h"



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

std::string TitleList::getTitle(unsigned int titlePos, unsigned int titleVarPos)
{
	if (titlePos <= title.size() && titlePos >= 0 && !title.empty() && 
		titleVarPos <= imdb::totTitleVars && titleVarPos >= 0)
	{
		return title.at(titlePos).getTitleVars(titleVarPos);
	}
	else{
		return "";
	}
}
