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
	bool removeFilmEntryExample(std::istream &fin);

	std::string getTitleVar(int titlePos, int titleVarPos);
	void setTitleVar(int titlePos, int titleVarPos, std::string name);

	void addTitleEntry(Title titleEntry);
	Title getTitleEntry(int titleEntryPos);
};

#endif
