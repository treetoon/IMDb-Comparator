#include "TitleList.h"


TitleList::TitleList() : title(0)
{
	
}


TitleList::~TitleList()
{
}

bool TitleList::writeFile(const std::ostream &out)
{
	//write all titles to a file

	if (out){
		for (size_t i = 0; i < title.size(); i++)
		{
			title[i].writeTitle(out);
		}
		return true;
	}
	return false;
}

bool TitleList::readFile(std::ifstream &fin)
{
	//adds titles from file to array
	if (fin){
		while (!fin.eof())
		{
			Title temp;
			if (temp.readTitle(fin)){
				title.push_back(temp);
			}
		}
		return true;
	}
	return false;
}
