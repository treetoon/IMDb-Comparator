#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt Library
#include <QtWidgets/QMainWindow>
#include <QStandardItem>

//Qt Auto Generated Files
#include "ui_mainwindow.h" 

//qt_IMDb DLL
#include "titlelist.h"

//Qt Forms
#include "aboutdialog.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	void readFile(QString &file_temp, TitleList &tl_temp);
	void updateTable();
	
	void sortColumns(const int &TITLE_VAR);
	void copyModel(QStandardItemModel &from_model, QStandardItemModel &to_model);

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);

private slots:
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
	void on_actionLoad_File_1_triggered();
	void on_actionLoad_File_2_triggered();
	void on_comboBox_currentIndexChanged(int index);

private:
	void setupTable();
	void setGroupBoxTitles();
	void print_totalRuntime(QStandardItemModel &model_temp, QLabel &label_temp);

	//print to the table functions
	void printTable(TitleList &tl, QStandardItemModel &model);
	void printTable_removeDuplicates();
	void printTable_showDuplicates();

	Ui::mainwindowClass ui;
	aboutDialog *about;
	QString file_1, file_2;
	TitleList tl1, tl2;
	QStandardItemModel *model_1, *model_2;
};



#endif // QT_IMDB_H
