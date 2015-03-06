#ifndef TITLE_H
#define TITLE_H

#include <string>
#include <iostream>
#include <fstream>

class Title
{
private:
	//Title vars
	int position;

	std::string constID; //arbitrary number such as "tt0295297"
	std::string created;
	std::string modified;

	std::string description;
	std::string title;
	std::string titleType; //documentary, full feature etc
	std::string directors;

	double youRated;
	double IMDbRating;
	int runtime; //minutes
	int year;

	std::string genres;
	int numOfVotes;
	std::string releaseDate;
	std::string URL;

public:
	Title();
	~Title();

	bool readTitle(std::istream &fin);
	bool writeTitle(std::ostream &out);

	std::string getTitle();
	void setf();
};

#endif