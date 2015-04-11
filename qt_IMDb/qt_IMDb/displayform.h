#ifndef DISPLAYFORM_H
#define DISPLAYFORM_H

#include <QWidget>

namespace Ui {
class displayForm;
}

class displayForm : public QWidget
{
    Q_OBJECT

public:
    explicit displayForm(QWidget *parent = 0);
    ~displayForm();

private:
    Ui::displayForm *ui;
};

#endif // DISPLAYFORM_H
