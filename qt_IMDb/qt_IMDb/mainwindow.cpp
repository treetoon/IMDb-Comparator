//Qt Library
#include <QFileDialog>
#include <QDropEvent>
#include <QtCore\qmimedata.h>

//Qt Forms
#include "mainwindow.h"

//Definitions
#include "qt_defines.h"
#include "imdb_defines.h"
using namespace imdb;


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent /*, Qt::FramelessWindowHint*/)
{
	ui.setupUi(this);
	about = new aboutDialog();
	dragPos = new QPoint;

	//create the tables
	model_1 = new QStandardItemModel(0, TOT_TITLE_VARS, this);
	model_2 = new QStandardItemModel(0, TOT_TITLE_VARS, this);

	//setup table and customize our table
	setupTable();
}

MainWindow::~MainWindow()
{
	delete about;
	delete model_1, model_2;
	delete dragPos;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	//if (event->button() == Qt::LeftButton) {
	//	*dragPos = event->globalPos() - frameGeometry().topLeft();
	//	event->accept();
	//}
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
	//if (event->buttons() & Qt::LeftButton) {
	//	move(event->globalPos() - *dragPos);
	//	event->accept();
	//}
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
}

void MainWindow::on_actionExit_triggered()
{
	QApplication::quit();
}

void MainWindow::on_actionLoad_File_1_triggered()
{
	readFile(file_1, tl1);
	ui.comboBox->setCurrentIndex(0); //reset combo sorting box
	updateTable();
}

void MainWindow::on_actionLoad_File_2_triggered()
{
	readFile(file_2, tl2);
	ui.comboBox->setCurrentIndex(0); //reset combo sorting box
	updateTable();
}

void MainWindow::on_actionAbout_triggered()
{
	about->show();
}

void MainWindow::readFile(QString &file_temp, TitleList &tl_temp)
{
	std::ifstream fin;

	//store the filename directory
	file_temp = QFileDialog::getOpenFileName(this, "Select one file to open",
		"C://", "IMDb files (*.csv);;Text files (*.txt);;All files (*.*)");

	//set filename directory
	fin.open(file_temp.toLocal8Bit().constData());

	//read from .csv file and save all titles into the TitleList
	tl_temp.readFile(fin);

	fin.close();
	updateTable();
}

void MainWindow::autoReadFiles()
{
	std::ifstream fin;
	TitleList tl_temp;

	//get an array containing two path urls
	std::string *fullPathsArr = tl_temp.autoReadFiles();

	//set filename directory
	file_1 = QString::fromStdString(fullPathsArr[0]);
	file_2 = QString::fromStdString(fullPathsArr[1]);

	//read from .csv file and save all titles into the TitleList
	fin.open(file_1.toLocal8Bit().constData());
	tl1.readFile(fin);
	fin.close();

	fin.open(file_2.toLocal8Bit().constData());
	tl2.readFile(fin);
	fin.close();

	updateTable();
}

void MainWindow::setGroupBoxTitles()
{
	//set .csv file names as group box titles
	if (!file_1.isEmpty()){
		ui.groupBox_1->setTitle(file_1);
		ui.groupBox_infoPage_1->setTitle(file_1);
	}else{
		ui.groupBox_1->setTitle("#1 .csv file");
		ui.groupBox_infoPage_1->setTitle("#1 .csv file");
	}
	if (!file_2.isEmpty()){
		ui.groupBox_2->setTitle(file_2);
		ui.groupBox_infoPage_2->setTitle(file_2);
	}else{
		ui.groupBox_2->setTitle("#2 .csv file");
		ui.groupBox_infoPage_2->setTitle("#2 .csv file");
	}
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
	switch (index)
	{
	case 0: //Show All (Default: regular table order)
		printTable(tl1, *model_1);
		printTable(tl2, *model_2);
		break;
	case 1: //Remove Duplicates (for both tables)
		printTable_removeDuplicates();
		break;
	case 2: //Only Show Duplicates (for both tables)
		printTable_showDuplicates();
		break;
	default:
		break;
	}

	sortColumns(IMDB_RATING);

	//reset (unselect) the checkbox for Feature Films filter
	ui.checkBox_featureFilms->setChecked(false);

	//total film runtime for each table filtered
	print_totalRuntime(*model_1, *ui.label_numHrs_filter_1);
	print_totalRuntime(*model_2, *ui.label_numHrs_filter_2);
}

void MainWindow::on_checkBox_featureFilms_stateChanged(int state)
{
	if (state){ //select
		printTable_showFeatureFilms();
	}
	else{ //unselect
		updateTable();
	}

	//total film runtime for each table filtered
	print_totalRuntime(*model_1, *ui.label_numHrs_filter_1);
	print_totalRuntime(*model_2, *ui.label_numHrs_filter_2);
}

void MainWindow::setupTable()
{
	//display models in tableView
	ui.tableView_1->setModel(model_1);
	ui.tableView_2->setModel(model_2);

	//enable column sorting on click
	ui.tableView_1->setSortingEnabled(true);
	ui.tableView_2->setSortingEnabled(true);

	//disable the ability to edit
	ui.tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//enable movable columns
	ui.tableView_1->horizontalHeader()->setSectionsMovable(true);
	ui.tableView_2->horizontalHeader()->setSectionsMovable(true);

	//set header labels
	QStringList HeaderLabels;
	SET_HEADER_LABELS(HeaderLabels);
	model_1->setHorizontalHeaderLabels(HeaderLabels);
	model_2->setHorizontalHeaderLabels(HeaderLabels);

	//set row heights
	ui.tableView_1->verticalHeader()->setDefaultSectionSize(23);
	ui.tableView_2->verticalHeader()->setDefaultSectionSize(23);

	//set table box column widths
	SET_TABLE_COLUMN_WIDTH(tableView_1);
	SET_TABLE_COLUMN_WIDTH(tableView_2);

	//read .csv files from the base folder
	autoReadFiles();
}

void MainWindow::updateTable()
{
	//set table sizes
	model_1->setRowCount(tl1.getSizeOfVector());
	model_2->setRowCount(tl2.getSizeOfVector());

	//print all items to the tables
	printTable(tl1, *model_1);
	printTable(tl2, *model_2);

	//sort by default
	sortColumns(IMDB_RATING);

	//set titles for each table
	setGroupBoxTitles();

	//total film runtime for each table
	print_totalRuntime(*model_1, *ui.label_numHrs_1);
	print_totalRuntime(*model_2, *ui.label_numHrs_2);

	//total film runtime for each table filtered
	print_totalRuntime(*model_1, *ui.label_numHrs_filter_1);
	print_totalRuntime(*model_2, *ui.label_numHrs_filter_2);
}


void MainWindow::printTable(TitleList &tl, QStandardItemModel &model)
//prints everything possible into the table
{
	//print table
	for (unsigned int row = 0; row < tl.getSizeOfVector(); row++){
		for (unsigned int column = 0; column < imdb::TOT_TITLE_VARS; column++)
		{
			//convert string to Qstring then store the title in item
			QStandardItem *item = new QStandardItem(QString::fromStdString(tl.getTitleVar(row, column)));

			//print item to table
			model.setItem(row, column, item);
		}
	}
}

void MainWindow::printTable_removeDuplicates()
//compares the two .csv files and removes duplicates, then prints to the table
{
	//print all items out first or the sorting may sort off of an earlier table sort
	printTable(tl1, *model_1);
	printTable(tl2, *model_2);

	std::vector<int> index_list_y;

	//delete duplicates in table #1 starting from bottom
	for (int x = tl1.getSizeOfVector() - 1; x >= 0; x--)
	{
		for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
		{
			if (model_1->data(model_1->index(x, CONSTID)) ==
				model_2->data(model_2->index(y, CONSTID)))
			{
				model_1->removeRow(x);
				index_list_y.push_back(y); //store index for #2 table due to sync issues

				break; //found a duplicate, break out to avoid overhead
			}
		}
	}

	//sort the list
	std::sort(index_list_y.begin(), index_list_y.end());

	//delete duplicates in table #2 starting from bottom
	for (int i = index_list_y.size() - 1; i >= 0; i--)
		model_2->removeRow(index_list_y.at(i));
}

void MainWindow::printTable_showDuplicates()
//compares the two .csv files and shows only the duplicates, then prints to the table
{
	//print all items out first or the sorting may sort off of an earlier table sort
	printTable(tl1, *model_1);
	printTable(tl2, *model_2);

	bool found_duplicate = false;

	//find duplicates in the tables starting from bottom
	for (int x = tl1.getSizeOfVector() - 1; x >= 0; x--){
		for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
		{
			if (model_1->data(model_1->index(x, CONSTID)) ==
				model_2->data(model_2->index(y, CONSTID)))
			{
				found_duplicate = true;
				break; //found a duplicate, break out to avoid overhead
			}
		}
		if (!found_duplicate){
			model_1->removeRow(x);
		}
		found_duplicate = false; //reset
	}

	//identical but checks from the other table, seemed equally 
	//asinine to create a function specifically for this function
	for (int y = tl2.getSizeOfVector() - 1; y >= 0; y--){
		for (unsigned int x = 0; x < tl1.getSizeOfVector(); x++)
		{
			if (model_2->data(model_2->index(y, CONSTID)) ==
				model_1->data(model_1->index(x, CONSTID)))
			{
				found_duplicate = true;
				break; //found a duplicate, break out to avoid overhead
			}
		}
		if (!found_duplicate){
			model_2->removeRow(y);
		}
		found_duplicate = false; //reset
	}
}

void MainWindow::sortColumns(const int &TITLE_VAR)
{
	if (!ui.tableView_1->isSortingEnabled()){
		ui.tableView_1->setSortingEnabled(true);
	}

	//sorts the column in the table
	ui.tableView_1->sortByColumn(TITLE_VAR, Qt::DescendingOrder);
	ui.tableView_2->sortByColumn(TITLE_VAR, Qt::DescendingOrder);
}

void MainWindow::printTable_showFeatureFilms()
{
	//remove entries that are not Feature Films
	for (int x = model_1->rowCount()-1; x >= 0; x--){
		if (model_1->item(x, TITLE_TYPE)->text().toStdString() != "Feature Film")
		{
			model_1->removeRow(x);
		}
	}
	for (int x = model_2->rowCount() - 1; x >= 0; x--){
		if (model_2->item(x, TITLE_TYPE)->text().toStdString() != "Feature Film")
		{
			model_2->removeRow(x);
		}
	}
}



void MainWindow::copyModel(QStandardItemModel &from_model, QStandardItemModel &to_model)
//copies from a model to another model
{
	//clear rows
	to_model.removeRows(0, to_model.rowCount());

	for (int x = 0; x < from_model.rowCount(); x++){
		for (unsigned int y = 0; y < TOT_TITLE_VARS; y++)
		{
			to_model.setItem(x, y, from_model.item(x, y)->clone());
		}
	}
}

void MainWindow::print_totalRuntime(QStandardItemModel &model_temp, QLabel &label_temp)
{
	int sum = 0;

	//calculate minutes for the total runtime of a table
	for (int x = 0; x < model_temp.rowCount(); x++){
		if (!model_temp.item(x, RUNTIME)->text().isEmpty())
			sum += stoi(model_temp.item(x, RUNTIME)->text().toStdString());
	}

	//set the text by hours
	label_temp.setText(QString::number(sum / 60));
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
	//if (event->mimeData()->hasUrls())
	//	event->acceptProposedAction();
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
	//event->accept();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
	//event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
	//if (event->mimeData()->hasUrls())
	//{
	//	foreach(QUrl url_list, event->mimeData()->urls())
	//	{
	//		file_1 = url_list.toLocalFile(); //get path
	//	}


	//	//set filename
	//	std::ifstream fin;
	//	fin.open(file_1.toLocal8Bit().constData());

	//	//read from .csv file and save all titles into the TitleList
	//	tl1.readFile(fin);

	//	//print and update table information
	//	updateTable();
	//}
}


