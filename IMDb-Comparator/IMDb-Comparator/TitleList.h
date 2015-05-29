#ifndef TITLELIST_H
#define TITLELIST_H

#include <vector>
#include <fstream>

#include "Title.h"



class TitleList 
{
private:
	std::vector<Title> title;
public:
	TitleList();
	~TitleList();	

	bool writeFile(std::ostream &out);
	bool readFile(std::istream &fin);

	int getSizeOfVector();
	std::string getTitle(unsigned int titlePos, unsigned int titleVarPos);
};

#endif
