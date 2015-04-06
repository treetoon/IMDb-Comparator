#include "qt_imdb.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	qt_IMDb w;
	w.show();





	return app.exec();
}
