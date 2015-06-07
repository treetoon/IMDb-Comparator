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
	void setTitleList(const TitleList &tl, const TitleList &tl2);
	void updateFormModel();

	void printTable(TitleList &tl, QStandardItemModel &model);
	void printTable_removeDuplicates();
	void printTable_showDuplicates();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::displayForm *ui;

	QStandardItemModel *model, *model_2;
	TitleList tl, tl2;
};

#endif // DISPLAYFORM_H
