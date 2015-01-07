#include "Title.h"
#include "TitleList.h"



int main()
{
	std::ifstream fin("MovieList.csv");

	Title t;
	t.readTitle(fin);

	system("PAUSE");
	return 0;
}