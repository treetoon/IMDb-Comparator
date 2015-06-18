#include "tablefilter.h"

//Definitions
#include "imdb_defines.h"
using namespace imdb;



TableFilter::TableFilter()
{
}

TableFilter::~TableFilter()
{
}

void TableFilter::printTable(TitleList &tl, QStandardItemModel &model)
//prints everything possible into the table
{
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

void TableFilter::printTables(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2)
//prints both tables
{
	printTable(tl1, model_1);
	printTable(tl2, model_2);
}

void TableFilter::printTables_showDuplicates(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2)
{
	//print all items out first or the sorting may sort off of an earlier table sort
	printTables(tl1, model_1, tl2, model_2);

	bool found_duplicate = false;

	//find duplicates in the tables starting from bottom
	for (int x = tl1.getSizeOfVector() - 1; x >= 0; x--){
		for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
		{
			if (model_1.data(model_1.index(x, CONSTID)) ==
				model_2.data(model_2.index(y, CONSTID)))
			{
				found_duplicate = true;
				break; //found a duplicate, break out to avoid overhead
			}
		}
		if (!found_duplicate){
			model_1.removeRow(x);
		}
		found_duplicate = false; //reset
	}

	//identical but checks from the other table, seemed equally 
	//asinine to create a function specifically for this function
	for (int y = tl2.getSizeOfVector() - 1; y >= 0; y--){
		for (unsigned int x = 0; x < tl1.getSizeOfVector(); x++)
		{
			if (model_2.data(model_2.index(y, CONSTID)) ==
				model_1.data(model_1.index(x, CONSTID)))
			{
				found_duplicate = true;
				break; //found a duplicate, break out to avoid overhead
			}
		}
		if (!found_duplicate){
			model_2.removeRow(y);
		}
		found_duplicate = false; //reset
	}
}

void TableFilter::printTable_removeDuplicates(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2)
//compares the two .csv files and removes duplicates, then prints to the table
{
	//print all items out first or the sorting may sort off of an earlier table sort
	printTables(tl1, model_1, tl2, model_2);

	std::vector<int> index_list_y;

	//delete duplicates in table #1 starting from bottom
	for (int x = tl1.getSizeOfVector() - 1; x >= 0; x--)
	{
		for (unsigned int y = 0; y < tl2.getSizeOfVector(); y++)
		{
			if (model_1.data(model_1.index(x, CONSTID)) ==
				model_2.data(model_2.index(y, CONSTID)))
			{
				model_1.removeRow(x);
				index_list_y.push_back(y); //store index for #2 table due to sync issues

				break; //found a duplicate, break out to avoid overhead
			}
		}
	}

	//sort the list
	std::sort(index_list_y.begin(), index_list_y.end());

	//delete duplicates in table #2 starting from bottom
	for (int i = index_list_y.size() - 1; i >= 0; i--)
		model_2.removeRow(index_list_y.at(i));
}

void TableFilter::printTable_showFeatureFilms(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2)
{
	//remove entries that are not Feature Films
	for (int x = model_1.rowCount() - 1; x >= 0; x--){
		if (model_1.item(x, TITLE_TYPE)->text().toStdString() != "Feature Film")
		{
			model_1.removeRow(x);
		}
	}
	for (int x = model_2.rowCount() - 1; x >= 0; x--){
		if (model_2.item(x, TITLE_TYPE)->text().toStdString() != "Feature Film")
		{
			model_2.removeRow(x);
		}
	}
}

void TableFilter::sortColumns(Ui::mainwindowClass &ui, const int &TITLE_VAR)
//sorts the column in the table
{
	ui.tableView_1->sortByColumn(TITLE_VAR, Qt::DescendingOrder);
	ui.tableView_2->sortByColumn(TITLE_VAR, Qt::DescendingOrder);
}
