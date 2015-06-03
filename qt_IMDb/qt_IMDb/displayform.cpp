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
	delete model, model_2;
}

void displayForm::setGroupBoxTitles(QString &file_1, QString &file_2)
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

void displayForm::setTitleList(const TitleList &tl, const TitleList &tl2)
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

	//print all items to the tables
	printTable(tl, *model);
	printTable(tl2, *model_2);

	//display models in tableView
	ui->tableView->setModel(model);
	ui->tableView_2->setModel(model_2);

	//sets the header labels, row heights, column widths etc
	designTableRows();
}


void displayForm::on_comboBox_currentIndexChanged(int index)
{
	switch (index)
	{
	case 0: //Default / No Sorting

		//prints regular table order
		printTable(tl, *model);
		printTable(tl2, *model_2);
		break;
	case 1: //Remove Duplicates

		//prints table order without duplicates
		printTable_RemoveDuplicates();
		break;
	case 2:

		break;
	default:
		break;
	}
}

void displayForm::designTableRows()
{
	//disable the ability to edit
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//set header labels
	QStringList HeaderLabels;
	SET_HEADER_LABELS(HeaderLabels);

	model->setHorizontalHeaderLabels(HeaderLabels);
	model_2->setHorizontalHeaderLabels(HeaderLabels);

	//set row heights
	ui->tableView->verticalHeader()->setDefaultSectionSize(23);
	ui->tableView_2->verticalHeader()->setDefaultSectionSize(23);

	//set table box column widths
	SET_TABLE_COLUMN_WIDTH(tableView);
	SET_TABLE_COLUMN_WIDTH(tableView_2);
}

bool displayForm::setIf_TitleList_HasExample(unsigned int &example, TitleList &tl)
//checks if the first entry in the TitleList (.csv file) is considered an 
//example, i.e, looking like this: "position","const","created".. etc 
//"Title" is the first element in the organized table within TitleList, 
//thus why it is checked
{
	if (tl.getTitleVar(0, 0) == "Title"){
		example--;
		return true;
	}
	else{
		return false;
	}
}

void displayForm::printTable(TitleList &tl, QStandardItemModel &model)
//prints everything possible into the table
{
	//.csv files comes with an example as the first film entry, 
	//if it's there we don't print it to the table
	unsigned int example = 0;
	setIf_TitleList_HasExample(example, tl);

	//print table
	for (unsigned int row = 0; row < tl.getSizeOfVector(); row++){
		for (unsigned int column = 0; column < imdb::TOT_TITLE_VARS; column++)
		{
			//convert string to Qstring then store the title in item
			QStandardItem *item = new QStandardItem(QString::fromStdString(tl.getTitleVar(row, column)));

			//print item to table
			model.setItem(row + example, column, item);
		}
	}
}

void displayForm::printTable_RemoveDuplicates()
//compares the two .csv files and removes duplicates, then prints to the table
{

	//terrible code, table 2 broken

	int actual_row = 0;

	for (unsigned int x = 0; x < tl.getSizeOfVector(); x++)
	{
		for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
		{
			if (tl.getTitleVar(x + 1, CONSTID) == tl2.getTitleVar(y + 1, CONSTID)) //+1 skip example temp
			{
				model->removeRow(x + actual_row);
				model_2->removeRow(y + actual_row);
				actual_row--;

				//end loop
				break;
			}
		}
	}


}