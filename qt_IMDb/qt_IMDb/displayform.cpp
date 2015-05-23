#include "displayform.h"
#include "ui_displayform.h"

displayForm::displayForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayForm)
{
    ui->setupUi(this);
	this->setWindowTitle("Film List Comparisons");

	//create the tables
	model = new QStandardItemModel(1000, 10, this);
	model_2 = new QStandardItemModel(1000, 10, this);
	
	//create item
	item = new QStandardItem;

	item->setText("default");
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
		
	} else if (index == 1){
		item->setText("option01");
	}
}
