#ifndef DISPLAYFORM_H
#define DISPLAYFORM_H

#include <QWidget>
#include <QStandardItem>

#include "TitleList.h"



namespace Ui {
class displayForm;
}

class displayForm : public QWidget
{
    Q_OBJECT

public:
    explicit displayForm(QWidget *parent = 0);
    ~displayForm();

	void setGroupBoxTitles(QString &file_1, QString &file_2);
	void setTitleList(const TitleList &tl_1, const TitleList &tl2);
	void updateFormModel();
	void sortColumns(const int &TITLE_VAR);
	void copyModel(QStandardItemModel &from_model, QStandardItemModel &to_model);

	void printTable(TitleList &tl, QStandardItemModel &model);
	void printTable_removeDuplicates();
	void printTable_showDuplicates();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::displayForm *ui;

	QStandardItemModel *model_1, *model_2;
	TitleList tl1, tl2;
};

#endif // DISPLAYFORM_H
