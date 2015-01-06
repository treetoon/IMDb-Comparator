#pragma once
#include <string>


class Movie
{
private:
	int position;
	int constNum;
	std::string created;
	std::string modified;
	std::string description;
	std::string title;
	std::string titleType;
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
	Movie();
	~Movie();

	void read();
	void write();


};

