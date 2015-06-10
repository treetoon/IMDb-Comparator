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
	model_1 = new QStandardItemModel(0, TOT_TITLE_VARS, this);
	model_2 = new QStandardItemModel(0, TOT_TITLE_VARS, this);
}

displayForm::~displayForm()
{
    delete ui;
	delete model_1, model_2;
}

void displayForm::setGroupBoxTitles(QString &file_1, QString &file_2)
{
	//set .csv file names as group box titles
	if (!file_1.isEmpty())
		ui->groupBox_1->setTitle(file_1);
	else
		ui->groupBox_1->setTitle("#1 .csv file");

	if (!file_2.isEmpty())
		ui->groupBox_2->setTitle(file_2);
	else
		ui->groupBox_2->setTitle("#2 .csv file");
}

void displayForm::setTitleList(const TitleList &tl, const TitleList &tl2)
{
	this->tl1 = tl;
	this->tl2 = tl2;
}

void displayForm::updateFormModel()
{
	//set table sizes
	model_1->setRowCount(tl1.getSizeOfVector());
	model_2->setRowCount(tl2.getSizeOfVector());

	//print all items to the tables
	printTable(tl1, *model_1);
	printTable(tl2, *model_2);

	//display models in tableView
	ui->tableView_1->setModel(model_1);
	ui->tableView_2->setModel(model_2);

	//enable column sorting on click, then sort
	ui->tableView_1->setSortingEnabled(true);
	ui->tableView_2->setSortingEnabled(true);
	sortColumns(IMDB_RATING);

	//disable the ability to edit
	ui->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//enable movable columns
	ui->tableView_1->horizontalHeader()->setSectionsMovable(true);
	ui->tableView_2->horizontalHeader()->setSectionsMovable(true);

	//set header labels
	QStringList HeaderLabels;
	SET_HEADER_LABELS(HeaderLabels);
	model_1->setHorizontalHeaderLabels(HeaderLabels);
	model_2->setHorizontalHeaderLabels(HeaderLabels);

	//set row heights
	ui->tableView_1->verticalHeader()->setDefaultSectionSize(23);
	ui->tableView_2->verticalHeader()->setDefaultSectionSize(23);

	//set table box column widths
	SET_TABLE_COLUMN_WIDTH(tableView_1);
	SET_TABLE_COLUMN_WIDTH(tableView_2);
}

void displayForm::on_comboBox_currentIndexChanged(int index)
{
	switch (index)
	{
	case 0: //Show All (Default: regular table order)
		printTable(tl1, *model_1);
		printTable(tl2, *model_2);
		sortColumns(IMDB_RATING);
		break;
	case 1: //Remove Duplicates (for both tables)
		printTable_removeDuplicates();
		sortColumns(IMDB_RATING);
		break;
	case 2: //Only Show Duplicates (for both tables)
		printTable_showDuplicates();
		sortColumns(IMDB_RATING);
		break;
	default:
		break;
	}
}

void displayForm::printTable(TitleList &tl, QStandardItemModel &model)
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

void displayForm::printTable_removeDuplicates()
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

void displayForm::printTable_showDuplicates()
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

void displayForm::sortColumns(const int &TITLE_VAR)
{
	if (!ui->tableView_1->isSortingEnabled()){
		ui->tableView_1->setSortingEnabled(true);
	}

	//sorts the column in the table
	ui->tableView_1->sortByColumn(TITLE_VAR, Qt::DescendingOrder);
	ui->tableView_2->sortByColumn(TITLE_VAR, Qt::DescendingOrder);
}

void displayForm::copyModel(QStandardItemModel &from_model, QStandardItemModel &to_model)
//copies from a model to another model
{
	//clear rows
	to_model.removeRows(0, to_model.rowCount());

	for (int x = 0; x < from_model.rowCount(); x++)
	{
		for (unsigned int y = 0; y < TOT_TITLE_VARS; y++){
			to_model.setItem(x, y, from_model.item(x, y)->clone());
		}
	}
}
