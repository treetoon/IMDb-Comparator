#ifndef TITLE_H
#define TITLE_H

#include <string>
#include <iostream>
#include <fstream>

class Title
{
private:
	int position;
	int constID; //arbitrary number such as "tt0295297"
	std::string created;
	std::string modified;
	std::string description;
	std::string title;
	std::string titleType; //documentary, full feature etc
	std::string directors;
	float youRated;
	float IMDbRating;
	int runtime; //minutes
	int year;
	std::string genres;
	int numOfVotes;
	std::string releaseDate;
	std::string URL;

public:
	Title();
	~Title();

	void readTitle(std::ifstream fin);
	void writeTitle(const std::ofstream fout);


};

#endif