#include "qt_imdb.h"
#include <QtWidgets/QApplication>

#include <Title.h>
#include <TitleList.h>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	qt_IMDb w;
	w.show();


	std::ifstream fin("MovieList.csv");
	std::ofstream fout("out.csv");

	TitleList tl;
	tl.readFile(fin);
	tl.writeFile(fout);



	return app.exec();
}

