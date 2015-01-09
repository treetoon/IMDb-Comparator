#include "TitleList.h"


TitleList::TitleList() : t_arr(0)
{
}


TitleList::~TitleList()
{
}

void TitleList::writeFile(std::ifstream &fin){

	//write all titles to a file

}

void TitleList::readFile(std::ifstream &fin)
{
	//adds titles from file to array
	while (fin && !fin.eof())
		readFile(fin);

}