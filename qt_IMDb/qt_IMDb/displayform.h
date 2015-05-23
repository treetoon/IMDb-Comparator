#ifndef DISPLAYFORM_H
#define DISPLAYFORM_H

#include <QWidget>
#include <QStandardItem>
#include <QHBoxLayout>

namespace Ui {
class displayForm;
}

class displayForm : public QWidget
{
    Q_OBJECT

public:
    explicit displayForm(QWidget *parent = 0);
    ~displayForm();

private slots:

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::displayForm *ui;

	QStandardItemModel *model;
	QStandardItemModel *model_2;

	//QHBoxLayout *hLayout;
	QStandardItem* item;
};

#endif // DISPLAYFORM_H
