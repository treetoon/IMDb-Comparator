#ifndef TITLELIST_H
#define TITLELIST_H

//Standard Library
#include <vector>
#include <fstream>

//Header
#include "title.h"



class TitleList 
{
public:
	TitleList();
	~TitleList();	

	bool writeFile(std::ostream &out);
	bool readFile(std::istream &fin);
	std::string *autoReadFiles();

	int getSizeOfVector();
	bool removeFilmEntryExample(std::istream &fin);

	std::string getTitleVar(int titlePos, int titleVarPos);
	void setTitleVar(int titlePos, int titleVarPos, std::string name);

	void addTitleEntry(Title titleEntry);
	Title getTitleEntry(int titleEntryPos);

private:
	std::vector<Title> title;
};

#endif
