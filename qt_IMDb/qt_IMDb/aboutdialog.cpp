//Qt Auto Generated Files
#include "ui_aboutdialog.h"

//Qt Forms
#include "aboutdialog.h"


aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

void aboutDialog::on_commandLinkButton_clicked()
{
	this->close();
}
