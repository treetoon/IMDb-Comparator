#include <string>

#include "imdb_defines.h"
using namespace imdb;

//forms
#include "displayform.h"
#include "qt_imdb.h"

#include "ui_displayform.h"



displayForm::displayForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::displayForm)
{
    ui->setupUi(this);
	this->setWindowTitle("Film List Comparisons");

	//create the tables
	model = new QStandardItemModel(0, TOT_TITLE_VARS, this);
	model_2 = new QStandardItemModel(0, TOT_TITLE_VARS, this);
}

displayForm::~displayForm()
{
    delete ui;

	delete model;
	delete model_2;
}

void displayForm::setGroupBoxTitles(QString file_1, QString file_2)
{
	//set .csv file names as group box titles
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
	//set table sizes
	model->setRowCount(tl.getSizeOfVector());
	model_2->setRowCount(tl2.getSizeOfVector());

	
	//sort columns on click
	//

	//no edit allowed
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//.csv files comes with an example as the first film entry, 
	//if it's there we don't print it to the table
	unsigned int example = 0;
	unsigned int example_2 = 0;

	if (tl.getTitleVar(0, 0) == "Title"){ //the example name of the first entry
		example--;
	}
	if (tl2.getTitleVar(0, 0) == "Title"){
		example_2--;
	}

	//print all items 
	for (unsigned int row = 0; row < tl.getSizeOfVector(); row++){
		for (unsigned int column = 0; column < imdb::TOT_TITLE_VARS; column++)
			{
				//convert string to Qstring then store title in item
				QStandardItem *item = new QStandardItem(QString::fromStdString(tl.getTitleVar(row, column)));

				//print item to table
				model->setItem(row + example, column, item);
			}
	}

	//do the same for the second table
	for (unsigned int row = 0; row < tl2.getSizeOfVector(); row++){
		for (unsigned int column = 0; column < imdb::TOT_TITLE_VARS; column++)
		{
			QStandardItem *item_2 = new QStandardItem(QString::fromStdString(tl2.getTitleVar(row, column)));

			model_2->setItem(row + example_2, column, item_2);
		}
	}

	//display models in tableView
	ui->tableView->setModel(model);
	ui->tableView_2->setModel(model_2);

	designTableRows();
}


void displayForm::on_comboBox_currentIndexChanged(int index)
{
	QStandardItem *itemz = new QStandardItem;

	TitleList temp = tl;
	TitleList temp_2 = tl2;
	const int constID = 14;


	switch (index)
	{
	case 0: //Default / No Sorting
		itemz->setText(QString::fromStdString("case 0 : default no sorting"));
		model->setItem(0, 0, itemz);
		break;




	case 1: //Remove Duplicates

		for (unsigned int i = 0; i < tl.getSizeOfVector(); i++)
		{
			for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
			{
				if (tl.getTitleVar(i, constID) == tl2.getTitleVar(y, constID))
				{
					temp.removeTitleEntry(i);
					temp_2.removeTitleEntry(y);
				}
			}
		}

		//print all items TEST ///////////////////////////////////////////////////
		for (unsigned int row = 0; row < temp.getSizeOfVector(); row++){
			for (unsigned int column = 0; column < imdb::TOT_TITLE_VARS; column++)
			{
				//convert string to Qstring then store title in item
				QStandardItem *item = new QStandardItem(QString::fromStdString(temp.getTitleVar(row, column)));

				//print item to table
				model->setItem(row, column, item);
			}
		}
		for (unsigned int row = 0; row < temp_2.getSizeOfVector(); row++){
			for (unsigned int column = 0; column < imdb::TOT_TITLE_VARS; column++)
			{
				QStandardItem *item_2 = new QStandardItem(QString::fromStdString(temp_2.getTitleVar(row, column)));

				model_2->setItem(row, column, item_2);
			}
		}






		break;
	case 2:
		itemz->setText(QString::fromStdString("case 2 : test"));
		model->setItem(0, 0, itemz);
		break;
	default:
		break;
	}
}

void displayForm::designTableRows()
{
	//set header labels
	QStringList HeaderLabels;
	HeaderLabels << "Title" << "Directors" << 
		"IMDb Rating" << "You rated" << "Year" << 
		"Runtime (mins)" << "Genres" << "Num. Votes" << 
		"Title type" <<	"Release Date (month/day/year)" << 
		"URL" << "Created" << "Modified" << 
		"Position" << "ConstID" << "Description";

	model->setHorizontalHeaderLabels(HeaderLabels);
	model_2->setHorizontalHeaderLabels(HeaderLabels);

	//set row heights
	ui->tableView->verticalHeader()->setDefaultSectionSize(23);
	ui->tableView_2->verticalHeader()->setDefaultSectionSize(23);

	//set table box column widths
	SET_TABLE_COLUMN_WIDTH(tableView);
	SET_TABLE_COLUMN_WIDTH(tableView_2);
}