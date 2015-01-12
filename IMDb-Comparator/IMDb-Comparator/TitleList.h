#ifndef TITLELIST_H
#define TITLELIST_H

#include "Title.h"
#include <vector>


class TitleList
{
private:
	std::vector<Title> title;
public:
	TitleList();
	~TitleList();

	bool writeFile(std::ostream &out);
	bool readFile(std::istream &fin);
};

#endif
