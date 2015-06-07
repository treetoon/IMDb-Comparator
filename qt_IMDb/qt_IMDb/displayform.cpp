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

	//print all items to the tables
	printTable(tl, *model);
	printTable(tl2, *model_2);

	//display models in tableView
	ui->tableView->setModel(model);
	ui->tableView_2->setModel(model_2);

	//sort columns on click
	ui->tableView->setSortingEnabled(true);
	ui->tableView->sortByColumn(imdb::IMDB_RATING, Qt::DescendingOrder);
	ui->tableView_2->setSortingEnabled(true);
	ui->tableView_2->sortByColumn(imdb::IMDB_RATING, Qt::DescendingOrder);

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

void displayForm::on_comboBox_currentIndexChanged(int index)
{
	switch (index)
	{
	case 0: //Show All (Default: regular table order)
		printTable(tl, *model);
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
	std::vector<int> index_list;

	//delete duplicates in table #1 starting from bottom
	for (int x = tl.getSizeOfVector() - 1; x >= 0; x--)
	{
		for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
		{
			if (model->data(model->index(x, imdb::CONSTID)) ==
				model_2->data(model_2->index(y, imdb::CONSTID)))
			{
				model->removeRow(x);

				//store index for #2 table due to sync issues
				index_list.push_back(y);
			}
		}
	}

	//sort the list
	std::sort(index_list.begin(), index_list.end());

	//delete duplicates in table #2 starting from bottom
	for (int i = index_list.size() - 1; i >= 0; i--)
		model_2->removeRow(index_list.at(i));
}

void displayForm::printTable_showDuplicates()
//compares the two .csv files and shows only the duplicates, then prints to the table
{
	//std::vector<int> index_list_1;
	//std::vector<int> index_list_2;

	////find duplicates in the tables starting from bottom
	//for (int x = tl.getSizeOfVector() - 1; x >= 0; x--)
	//{
	//	for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
	//	{
	//		if (model->data(model->index(x, imdb::CONSTID)) ==
	//			model_2->data(model_2->index(y, imdb::CONSTID)))
	//		{
	//			//store index for tables
	//			index_list_1.push_back(x);
	//			index_list_2.push_back(y);
	//		}
	//	}
	//}

	////sort the lists
	//std::sort(index_list_1.begin(), index_list_1.end());
	//std::sort(index_list_2.begin(), index_list_2.end());

	////delete non-duplicates in tables starting from bottom
	//for (int i = index_list_1.size() - 1; i >= 0; i--)
	//	model_2->removeRow(index_list_1.at(i));

	//for (int i = index_list_1.size() - 1; i >= 0; i--)
	//	model_2->removeRow(index_list_1.at(i));
}