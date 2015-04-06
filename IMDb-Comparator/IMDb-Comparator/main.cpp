#include "Title.h"
#include "TitleList.h"




int main()
{
	std::ifstream fin("MovieList.csv");
	std::ofstream fout("out.csv");

	TitleList tl;
	tl.readFile(fin);
	tl.writeFile(fout);







	
	system("PAUSE");
	return 0;
}