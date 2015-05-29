#include <string>

#include "imdb_constants.h"

//Windows
#include "displayform.h"
#include "qt_imdb.h"

#include "ui_displayform.h"



displayForm::displayForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::displayForm)
{
    ui->setupUi(this);
	this->setWindowTitle("Film List Comparisons");

	//create the tables
	model = new QStandardItemModel(0, imdb::totTitleVars, this);
	model_2 = new QStandardItemModel(0, imdb::totTitleVars, this);
}

displayForm::~displayForm()
{
    delete ui;

	delete model;
	delete model_2;
}

void displayForm::setGroupBoxTitles(QString file_1, QString file_2)
{
	if (!file_1.isEmpty())
		ui->groupBox->setTitle(file_1);
	else
		ui->groupBox->setTitle("#1 .csv file");

	if (!file_2.isEmpty())
		ui->groupBox_2->setTitle(file_2);
	else
		ui->groupBox_2->setTitle("#2 .csv file");
}

void displayForm::setTitleList(TitleList tl, TitleList tl2)
{
	this->tl = tl;
	this->tl2 = tl2;
}

void displayForm::updateFormModel()
{
	//clear the tables
	//

	//set table sizes
	model->setRowCount(tl.getSizeOfVector());
	model_2->setRowCount(tl2.getSizeOfVector());

	//set table box column width
	//
	
	//sort columns on click
	//
	

	//no box edit allowed
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//set header labels
	QStringList HeaderLabels;
	HeaderLabels << "Title" << "Title type" << "Directors" <<
		"IMDb Rating" << "You rated" << "Year" <<
		"Runtime (mins)" << "Genres" << "Num. Votes" <<
		"Release Date (month/day/year)" << "URL" << "Created" <<
		"Modified" << "Position" << "ConstID" << "Description";
		
	model->setHorizontalHeaderLabels(HeaderLabels);
	model_2->setHorizontalHeaderLabels(HeaderLabels);



	//.csv files comes with an example as the first film entry, 
	//if it's there we don't print it to the table
	unsigned int example = 0;
	unsigned int example_2 = 0;

	if (tl.getTitle(0, 0) == "Title"){ //the example name of the first entry
		example--;
	}
	if (tl2.getTitle(0, 0) == "Title"){
		example_2--;
	}

	for (unsigned int row = 0; row < tl.getSizeOfVector(); row++){
		for (unsigned int column = 0; column < imdb::totTitleVars; column++)
			{
				//convert string to Qstring then store title in item
				QStandardItem *item = new QStandardItem(QString::fromStdString(tl.getTitle(row, column)));

				//print item to table
				model->setItem(row + example, column, item);
			}
	}

	for (unsigned int row = 0; row < tl2.getSizeOfVector(); row++){
		for (unsigned int column = 0; column < imdb::totTitleVars; column++)
		{
			QStandardItem *item_2 = new QStandardItem(QString::fromStdString(tl2.getTitle(row, column)));

			model_2->setItem(row + example_2, column, item_2);
		}
	}

	//display models in tableView
	ui->tableView->setModel(model);
	ui->tableView_2->setModel(model_2);
}


void displayForm::on_comboBox_currentIndexChanged(int index)
{
	if (index == 0){
		//model->setItem(8, item);
		//item->setText("option00");
	}
	else if (index == 1){
		//item->setText("option01");


	}
}