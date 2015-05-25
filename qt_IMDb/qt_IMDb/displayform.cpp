#include "displayform.h"
#include "ui_displayform.h"

displayForm::displayForm(QWidget *parent) :
    QWidget(parent),
	ui(new Ui::displayForm), title_vars(16)
{
    ui->setupUi(this);
	this->setWindowTitle("Film List Comparisons");

	//create the tables
	model = new QStandardItemModel(1000, title_vars, this);
	model_2 = new QStandardItemModel(1000, title_vars, this);
	
	//create item
	item = new QStandardItem;

	

	item->setText("a");
	model->setItem(5, item);





	//display models in tableView
	ui->tableView->setModel(model);
	ui->tableView_2->setModel(model_2);
}

displayForm::~displayForm()
{
    delete ui;

	delete model;
	delete model_2;
}


void displayForm::on_comboBox_currentIndexChanged(int index)
{
	if (index == 0){
		model->setItem(8, item);
		item->setText("option00");
	} 
	else if (index == 1){
		item->setText("option01");
	}
}

void displayForm::setGroupBoxTitles(QString file_1, QString file_2)
{
	if (!file_1.isEmpty())
		ui->groupBox->setTitle(file_1);
	else
		ui->groupBox->setTitle("#1 .csv file");

	if (!file_2.isEmpty())
		ui->groupBox_2->setTitle(file_2);
	else
		ui->groupBox_2->setTitle("#2 .csv file");
}