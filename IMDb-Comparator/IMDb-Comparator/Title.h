#ifndef TITLE_H
#define TITLE_H

//Standard Library
#include <string>



class __declspec(dllexport) Title
{
private:
	//Title vars
	std::string position;
	std::string constID; //arbitrary number such as "tt0295297"
	std::string created;
	std::string modified;

	std::string description;
	std::string title;
	std::string titleType; //documentary, full feature etc
	std::string directors;

	std::string youRated;
	std::string IMDbRating;
	std::string runtime; //minutes
	std::string year;

	std::string genres;
	std::string numOfVotes;
	std::string releaseDate;
	std::string URL;

public:
	Title();
	~Title();

	bool readTitle(std::istream &fin);
	bool writeTitle(std::ostream &out);

	std::string getTitleVar(int titleVarPos);
	void setTitleVars(int titleVarPos, std::string name);
};



#endif