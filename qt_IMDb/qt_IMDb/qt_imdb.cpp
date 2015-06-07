#include <QFileDialog>

#include "qt_imdb.h"
#include "qt_defines.h"



qt_IMDb::qt_IMDb(QWidget *parent)
	: QMainWindow(parent), 
	runButtonState_01(false), 
	runButtonState_02(false)
{
	ui.setupUi(this);

	about = new aboutDialog();
	form = new displayForm();

	runButtonState();
}

qt_IMDb::~qt_IMDb()
{
	delete about;
	delete form;
}

void qt_IMDb::on_browseButton_clicked()
{
	readFile(file_1, *ui.browse_line_1, tl);
}

void qt_IMDb::on_browse_2Button_clicked()
{
	readFile(file_2, *ui.browse_line_2, tl2);
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
	//set group box title names
	form->setGroupBoxTitles(file_1, file_2);
	form->setTitleList(tl, tl2);
	
	//update model and force a maximized window
	form->updateFormModel();
	form->showMaximized();

	//force focus on form window and disable user input on other windows
	//setupUi overrides this
	form->setWindowModality(Qt::ApplicationModal);

	//launch displayform window
	form->show();
}

void qt_IMDb::runButtonState()
{
	if (!file_1.isEmpty()){
		runButtonState_01 = true;
	}else{
		runButtonState_01 = false;
	}

	if (!file_2.isEmpty()){
		runButtonState_02 = true;
	}else{
		runButtonState_02 = false;
	}

	//activate Show List Button when both files are loaded
	if (runButtonState_01 && runButtonState_02){
		ui.runButton->setEnabled(true);
	}else{
		ui.runButton->setEnabled(false);
	}
}

void qt_IMDb::readFile(QString &file_temp, QLineEdit &browse_line_temp, TitleList &tl_temp)
{
	std::ifstream fin;

	//get filename
	file_temp = QFileDialog::getOpenFileName(this, "Select one file to open",
		"C://", "IMDb files (*.csv);;Text files (*.txt);;All files (*.*)");

	//activate/deactive Show List Button
	runButtonState();

	//QString contains the directory; set dir in browse_line_2
	browse_line_temp.setText(file_temp);

	//set filename
	fin.open(file_temp.toLocal8Bit().constData());

	//read from .csv file and save all titles into the TitleList
	tl_temp.readFile(fin);
}
