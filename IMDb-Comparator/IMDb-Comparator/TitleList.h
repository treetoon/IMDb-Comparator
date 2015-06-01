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
	std::string getTitleVar(unsigned int titlePos, unsigned int titleVarPos);
	void setTitleVar(unsigned int titlePos, unsigned int titleVarPos, std::string name);

	void addTitleEntry(Title titleEntry);
	void removeTitleEntry(unsigned int titleEntryPos);
	Title getTitleEntry(unsigned int titleEntryPos);
};

#endif
