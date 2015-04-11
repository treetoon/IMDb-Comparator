#ifndef QT_IMDB_H
#define QT_IMDB_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_imdb.h"

#include <Title.h>
#include <TitleList.h>

#include "displayform.h"
#include "aboutdialog.h"

class qt_IMDb : public QMainWindow
{
	Q_OBJECT

public:
	qt_IMDb(QWidget *parent = 0);
	~qt_IMDb();


private slots:
    void on_browseButton_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_clearButton_clicked();

    void on_runButton_clicked();

private:
	Ui::qt_IMDbClass ui;

	aboutDialog *about;
	displayForm form;

	QStringList files;
	TitleList tl;
};

#endif // QT_IMDB_H
