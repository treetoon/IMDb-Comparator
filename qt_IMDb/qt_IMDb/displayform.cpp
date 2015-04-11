#include "displayform.h"
#include "ui_displayform.h"

displayForm::displayForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayForm)
{
    ui->setupUi(this);
}

displayForm::~displayForm()
{
    delete ui;
}
