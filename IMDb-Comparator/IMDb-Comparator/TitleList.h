#ifndef TITLELIST_H
#define TITLELIST_H

#include "Title.h"



class TitleList
{
private:
	Title *t_arr;
public:
	TitleList();
	~TitleList();

	void writeFile(std::ifstream &fin);
	void readFile(std::ifstream &fin);
};

#endif
