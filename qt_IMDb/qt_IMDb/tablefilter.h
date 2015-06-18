#ifndef TABLEFILTER_H
#define TABLEFILTER_H

//qt_IMDb DLL
#include "titlelist.h"

//Qt Library
#include <QStandardItem>

//Qt Auto Generated Files
#include "ui_mainwindow.h"

class TableFilter
{
public:
	TableFilter();
	~TableFilter();

protected:
	void printTable(TitleList &tl, QStandardItemModel &model);
	void printTables(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2);

	void printTables_showDuplicates(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2);
	void printTable_removeDuplicates(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2);
	void printTable_showFeatureFilms(TitleList &tl1, QStandardItemModel &model_1, TitleList &tl2, QStandardItemModel &model_2);

	void TableFilter::sortColumns(Ui::mainwindowClass &ui, const int &TITLE_VAR);
private:

};

#endif