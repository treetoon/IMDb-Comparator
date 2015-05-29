#include <QFileDialog>

#include "qt_imdb.h"



qt_IMDb::qt_IMDb(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	about = new aboutDialog();
	form = new displayForm();
}

qt_IMDb::~qt_IMDb()
{
	delete about;
	delete form;
}

void qt_IMDb::on_browseButton_clicked()
{
	std::ifstream fin;
	
	//get filename
	file_1 = QFileDialog::getOpenFileName(this, "Select one file to open", 
		"C://", "IMDb files (*.csv);;Text files (*.txt);;All files (*.*)");

	//QString contains the directory; set dir in browse_line_1
	ui.browse_line_1->setText(file_1);

	//set filename
	fin.open(file_1.toLocal8Bit().constData());

	//read from .csv file and save all titles into the TitleList
	tl.readFile(fin);
}

void qt_IMDb::on_browse_2Button_clicked()
{
	std::ifstream fin;

	//get filename
	file_2 = QFileDialog::getOpenFileName(this, "Select one file to open",
		"C://", "IMDb files (*.csv);;Text files (*.txt);;All files (*.*)");

	//QString contains the directory; set dir in browse_line_2
	ui.browse_line_2->setText(file_2);

	//set filename
	fin.open(file_2.toLocal8Bit().constData());

	//read from .csv file and save all titles into the TitleList
	tl2.readFile(fin);
}

void qt_IMDb::on_actionExit_triggered()
{
	QApplication::quit();
}

void qt_IMDb::on_actionAbout_triggered()
{
	about->show();
}

void qt_IMDb::on_runButton_clicked() //Show List Button
{
	form->setGroupBoxTitles(file_1, file_2);
	form->setTitleList(tl, tl2);





	//launch displayform window
	form->updateFormModel();
	form->show();
	
	//file output
	//std::ofstream fout0("out0.csv");
	//std::ofstream fout1("out1.csv");
	//tl.writeFile(fout0);
	//tl2.writeFile(fout1);
}

