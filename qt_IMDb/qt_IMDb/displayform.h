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

	void setGroupBoxTitles(QString file_1, QString file_2);

private slots:

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::displayForm *ui;

	QStandardItemModel *model, *model_2;
	QStandardItem *item;

	const int title_vars;
};

#endif // DISPLAYFORM_H
