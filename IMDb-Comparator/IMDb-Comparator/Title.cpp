#include <iostream>
#include <fstream>

#include "Title.h"
#include "imdb_constants.h"


Title::Title()
	: position(""), constID(""), created(""), modified(""),
description(""), title(""), titleType(""), directors(""),
youRated(""), IMDbRating(""), runtime(""), year(""), 
genres(""), numOfVotes(""), releaseDate(""), URL("")
{
}


Title::~Title()
{
}


bool Title::readTitle(std::istream &fin)
{
	//clean this function

	std::string line;
	int count = 0;



	if (fin) //file okay?
	{
		std::getline(fin, line);

		if (!line.empty())
		{
			for (int var = 1; var <= imdb::totTitleVars; var++)  //loop total vars
			{
				if (line.at(count) == '\"') //extra check that we can start reading
				{
					count++;

					while (line.at(count) != '\"') //read until " is found
					{
						//one char at a time

						if (var == 1 && line.at(0) == '\"') //first occurrence
						{
							position.append(line.substr(count, 1)); //position
						}

						else if (var == 2){
							constID.append(line.substr(count, 1));
						}

						else if (var == 3){
							created.append(line.substr(count, 1));
						}

						else if (var == 4){
							modified.append(line.substr(count, 1));
						}

						else if (var == 5){
							description.append(line.substr(count, 1));
						}

						else if (var == 6){
							title.append(line.substr(count, 1));
						}

						else if (var == 7){
							titleType.append(line.substr(count, 1));
						}

						else if (var == 8){
							directors.append(line.substr(count, 1));
						}

						else if (var == 9){
							youRated.append(line.substr(count, 1));
						}

						else if (var == 10){
							IMDbRating.append(line.substr(count, 1));
						}

						else if (var == 11){
							runtime.append(line.substr(count, 1));
						}

						else if (var == 12){
							year.append(line.substr(count, 1));
						}

						else if (var == 13){
							genres.append(line.substr(count, 1));
						}

						else if (var == 14){
							numOfVotes.append(line.substr(count, 1));
						}

						else if (var == 15){
							releaseDate.append(line.substr(count, 1));
						}

						else if (var == 16){
							URL.append(line.substr(count, 1));
						}

						count++;
					}
				}



				count = line.find(",", count);
				count++;
			}
			return true;
		}
	}
	return false;
}

bool Title::writeTitle(std::ostream &out)
{
	if (out)
	{
		out << "Position: " << position << " ";
		out << "Const: " << constID << " ";
		out << "Created: " << created << " ";
		out << "Modified: " << modified << " ";
		out << "Description: " << description << " ";
		out << "Title: " << title << " ";
		out << "titleType: " << titleType << " ";
		out << "directors: " << directors << " ";
		out << "youRated: " << youRated << " ";
		out << "IMDbRating: " << IMDbRating << " ";
		out << "runtime: " << runtime << " ";
		out << "year: " << year << " ";
		out << "genres: " << genres << " ";
		out << "numOfVotes: " << numOfVotes << " ";
		out << "releaseDate: " << releaseDate << " ";
		out << "URL: " << URL << " ";
		out << std::endl;

		return true;
	}
	else{
		return false;
	}
}

std::string Title::getTitleVars(unsigned int titleVarPos)
{
	//table order

	if (titleVarPos < imdb::totTitleVars && titleVarPos >= 0)
	{
		switch (titleVarPos)
		{
		case 0:
			return title;
		case 1:
			return titleType;
		case 2:
			return directors;
		case 3:
			return IMDbRating;
		case 4:
			return youRated ;
		case 5:
			return year;
		case 6:
			return runtime;
		case 7:
			return genres;
		case 8:
			return numOfVotes;
		case 9:
			return releaseDate;
		case 10:
			return URL;
		case 11:
			return created;
		case 12:
			return modified;
		case 13:
			return position;
		case 14:
			return constID;
		case 15:
			return description;
		default:
			return "";
		}
	}

	return "";
}
