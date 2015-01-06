#include "Title.h"


Title::Title()
	: position(0), constID(0), created(""), modified(""),
description(""), title(""), titleType(""), directors(""),
youRated(0.0), IMDbRating(0.0), runtime(0), year(0), 
genres(""), numOfVotes(0), releaseDate(""), URL("")
{

}


Title::~Title()
{
}


void Title::readTitle(std::ifstream fin)
{
	if (fin)
	{




	}
}

void Title::writeTitle(const std::ofstream fout)
{

}
