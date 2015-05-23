#include <QFileDialog>
#include <QMessageBox>

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

	files = QFileDialog::getOpenFileNames(
		this, "Select one or more files to open", "C://", 
		"IMDb files (*.csv);;Text files (*.txt);;All files (*.*)");

	for (short i = 0; i < files.length(); i++){
		fin.open(files.at(i).toLocal8Bit().constData());
	}

	
	
	
	
	tl.readFile(fin);
	

}

void qt_IMDb::on_actionExit_triggered()
{
	QApplication::quit();
}

void qt_IMDb::on_actionAbout_triggered()
{
	about->show();
}

void qt_IMDb::on_clearButton_clicked()
{
	//clear files
	//files.clear();
}

void qt_IMDb::on_runButton_clicked()
{
	//launch displayform window
	form->show();

	


	//std::ofstream fout("out.csv");
	//tl.writeFile(fout);
}
