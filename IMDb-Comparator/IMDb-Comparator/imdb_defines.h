#ifndef IMDB_DEFINES_H
#define IMDB_DEFINES_H

namespace imdb
{
	//all the variables per title, i.e title, position, directors etc
	const int TOT_TITLE_VARS =	16;

	//table order rather than input order
	const int TITLE =			 0;
	const int DIRECTORS =		 1;
	const int IMDB_RATING =		 2;
	const int YOU_RATED =		 3;
	const int YEAR =			 4;
	const int RUNTIME =			 5;
	const int GENRES =			 6;
	const int NUM_VOTES =		 7;
	const int TITLE_TYPE =		 8;
	const int RELEASE_DATE =	 9;
	const int URL =				10;
	const int CREATED =			11;
	const int MODIFIED =		12;
	const int POSITION =		13;
	const int CONSTID =			14;
	const int DESCRIPTION =		15;

	//base path
#define BASEPATH "\\base"
};

//end of string (row) check needs to happen before reading the current character
#define APPEND_CURRENT_CHARACTER(titleVar) \
	while (currentChar != line.length() && line.at(currentChar) != '\"') \
	{ \
		titleVar.append(line.substr(currentChar, 1)); \
		currentChar++; \
	} \





#endif