#include "Title.h"


Title::Title()
	: position(0), constID(""), created(""), modified(""),
description(""), title(""), titleType(""), directors(""),
youRated(0.0), IMDbRating(0.0), runtime(0), year(0), 
genres(""), numOfVotes(0), releaseDate(""), URL("")
{

}


Title::~Title()
{
}


void Title::readTitle(std::ifstream &fin)
{
	std::string line;
	int count = 0;

	if (fin)
	{



		std::getline(fin, line);

		count = line.find(",");
		count++;

		if (line.at(count) == '\"') //extra check that we can start reading
		{
			count++;

			while (line.at(count) != '\"') //read until " is found
			{
				constID.append(line.substr(count, 1));
				
				
				count++;
			}
		}


	}
}

void Title::writeTitle(const std::ofstream fout)
{

}
