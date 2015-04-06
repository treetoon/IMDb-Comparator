#ifndef QT_IMDB_H
#define QT_IMDB_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_imdb.h"

class qt_IMDb : public QMainWindow
{
	Q_OBJECT

public:
	qt_IMDb(QWidget *parent = 0);
	~qt_IMDb();

private:
	Ui::qt_IMDbClass ui;
};

#endif // QT_IMDB_H
