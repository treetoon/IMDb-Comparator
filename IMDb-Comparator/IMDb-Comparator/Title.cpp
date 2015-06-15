//Standard Library
#include <iostream>
#include <fstream>

//Header
#include "title.h"

//Definitions
#include "imdb_defines.h"


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
	if (fin){ //file okay check

		std::string line; //where the title row from the .csv file is stored
		unsigned int currentChar = 0; //current character we're reading

		//read the whole title row
		std::getline(fin, line); 

		if (!line.empty()) //make sure that the title row is not empty
		{
			//current variable we're reading in the title row, i.e title, directors etc
			for (unsigned int currentVar = 1; currentVar <= imdb::TOT_TITLE_VARS; currentVar++)
			{	
				currentChar++;
				
				//read one char at a time until " is found
				switch (currentVar)
				{
				case 1:
					APPEND_CURRENT_CHARACTER(position);
					break;
				case 2:
					APPEND_CURRENT_CHARACTER(constID);
					break;
				case 3:
					APPEND_CURRENT_CHARACTER(created);
					break;
				case 4:
					APPEND_CURRENT_CHARACTER(modified);
					break;
				case 5:
					APPEND_CURRENT_CHARACTER(description);
					break;
				case 6:
					APPEND_CURRENT_CHARACTER(title);
					break;
				case 7:
					APPEND_CURRENT_CHARACTER(titleType);
					break;
				case 8:
					APPEND_CURRENT_CHARACTER(directors);
					break;
				case 9:
					APPEND_CURRENT_CHARACTER(youRated);
					break;
				case 10:
					APPEND_CURRENT_CHARACTER(IMDbRating);
					break;
				case 11:
					APPEND_CURRENT_CHARACTER(runtime);
					break;
				case 12:
					APPEND_CURRENT_CHARACTER(year);
					break;
				case 13:
					APPEND_CURRENT_CHARACTER(genres);
					break;
				case 14:
					APPEND_CURRENT_CHARACTER(numOfVotes);
					break;
				case 15:
					APPEND_CURRENT_CHARACTER(releaseDate);
					break;
				case 16:
					APPEND_CURRENT_CHARACTER(URL);
					break;
				default:
					break;
				}
											
				//look for , from the position we're at, then set our current char
				currentChar = line.find(",", currentChar); 
				currentChar++;
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
		out << "Position: "		<< position << " ";
		out << "Const: "		<< constID << " ";
		out << "Created: "		<< created << " ";
		out << "Modified: "		<< modified << " ";
		out << "Description: "	<< description << " ";
		out << "Title: "		<< title << " ";
		out << "titleType: "	<< titleType << " ";
		out << "directors: "	<< directors << " ";
		out << "youRated: "		<< youRated << " ";
		out << "IMDbRating: "	<< IMDbRating << " ";
		out << "runtime: "		<< runtime << " ";
		out << "year: "			<< year << " ";
		out << "genres: "		<< genres << " ";
		out << "numOfVotes: "	<< numOfVotes << " ";
		out << "releaseDate: "	<< releaseDate << " ";
		out << "URL: "			<< URL << " ";
		out << std::endl;

		return true;
	}
	else{
		return false;
	}
}

std::string Title::getTitleVar(int titleVarPos)
{
	//table order

	if (titleVarPos < imdb::TOT_TITLE_VARS && titleVarPos >= 0)
	{
		switch (titleVarPos)
		{
		case 0:
			return title;
		case 1:
			return directors;
		case 2:
			return IMDbRating;
		case 3:
			return youRated;
		case 4:
			return year;
		case 5:
			return runtime;
		case 6:
			return genres;
		case 7:
			return numOfVotes;
		case 8:
			return titleType;
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
		}
	}

	return "EXIT_FAILURE";
}

void Title::setTitleVars(int titleVarPos, std::string name)
{
	//table order

	if (titleVarPos < imdb::TOT_TITLE_VARS && titleVarPos >= 0)
	{
		switch (titleVarPos)
		{
		case 0:
			title = name;
			break;
		case 1:
			directors = name;
			break;
		case 2:
			IMDbRating = name;
			break;
		case 3:
			youRated = name;
			break;
		case 4:
			year = name;
			break;
		case 5:
			runtime = name;
			break;
		case 6:
			genres = name;
			break;
		case 7:
			numOfVotes = name;
			break;
		case 8:
			titleType = name;
			break;
		case 9:
			releaseDate = name;
			break;
		case 10:
			URL = name;
			break;
		case 11:
			created = name;
			break;
		case 12:
			modified = name;
			break;
		case 13:
			position = name;
			break;
		case 14:
			constID = name;
			break;
		case 15:
			description = name;
			break;
		default:
			break;
		}
	}
}
