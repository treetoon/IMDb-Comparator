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


bool Title::readTitle(std::istream &fin)
{
	std::string line;
	int count = 0;
	const int lineVars = 16; //total variables (16)

	std::string position_ = "";
	std::string youRated_ = "";
	std::string IMDbRating_ = "";
	std::string runtime_ = "";
	std::string year_ = "";
	std::string numOfVotes_ = "";

	bool position_check = false, youRated_check = false,
		IMDbRating_check = false, runtime_check = false,
		year_check = false, numOfVotes_check = false;

	if (fin) //file okay?
	{
		std::getline(fin, line);

		if (!line.empty())
		{
			for (int var = 1; var <= lineVars; var++)  //loop total vars
			{
				if (line.at(count) == '\"') //extra check that we can start reading
				{
					count++;

					while (line.at(count) != '\"') //read until " is found
					{
						//one char at a time

						if (var == 1 && line.at(0) == '\"') //first occurrence
						{
							position_.append(line.substr(count, 1)); //position
							position_check = true;
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
							youRated_.append(line.substr(count, 1));
							youRated_check = true;
						}

						else if (var == 10){
							IMDbRating_.append(line.substr(count, 1));
							IMDbRating_check = true;
						}

						else if (var == 11){
							runtime_.append(line.substr(count, 1));
							runtime_check = true;
						}

						else if (var == 12){
							year_.append(line.substr(count, 1));
							year_check = true;
						}

						else if (var == 13){
							genres.append(line.substr(count, 1));
						}

						else if (var == 14){
							numOfVotes_.append(line.substr(count, 1));
							numOfVotes_check = true;
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

				//conversions
				if (position_check){
					position = atoi(position_.c_str());
					position_check = false;
				}
				else if (youRated_check){
					youRated = atof(youRated_.c_str());
					youRated_check = false;
				}
				else if (IMDbRating_check){
					IMDbRating = atof(IMDbRating_.c_str());
					IMDbRating_check = false;
				}
				else if (runtime_check){
					runtime = atoi(runtime_.c_str());
					runtime_check = false;
				}
				else if (year_check){
					year = atoi(year_.c_str());
					year_check = false;
				}
				else if (numOfVotes_check){
					numOfVotes = atoi(numOfVotes_.c_str());
					numOfVotes_check = false;
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

std::string Title::getTitle()
{
	return title;
}

void Title::setf()
{

}