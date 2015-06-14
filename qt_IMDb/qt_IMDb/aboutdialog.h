#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

//Qt Library
#include <QDialog>


namespace Ui {
class aboutDialog;
}

class aboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aboutDialog(QWidget *parent = 0);
    ~aboutDialog();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::aboutDialog *ui;
};

#endif // ABOUTDIALOG_H
