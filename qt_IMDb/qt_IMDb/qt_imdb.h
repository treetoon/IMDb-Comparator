#ifndef QT_IMDB_H
#define QT_IMDB_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_imdb.h"

#include "TitleList.h"

//forms
#include "displayform.h"
#include "aboutdialog.h"

class qt_IMDb : public QMainWindow
{
	Q_OBJECT

public:
	qt_IMDb(QWidget *parent = 0);
	~qt_IMDb();

	void runButtonState();
	void qt_IMDb::readFile(QString &file_temp, QLineEdit &browse_line_temp, TitleList &tl_temp);

private slots:
    void on_browseButton_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_runButton_clicked();
    void on_browse_2Button_clicked();

private:
	Ui::qt_IMDbClass ui;

	aboutDialog *about;
	displayForm *form;

	QString file_1, file_2;
	TitleList tl, tl2;

	bool runButtonState_01, runButtonState_02;
};



#endif // QT_IMDB_H
