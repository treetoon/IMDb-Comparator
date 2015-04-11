/********************************************************************************
** Form generated from reading UI file 'displayform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYFORM_H
#define UI_DISPLAYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displayForm
{
public:
    QGroupBox *groupBox;
    QScrollBar *verticalScrollBar;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *displayForm)
    {
        if (displayForm->objectName().isEmpty())
            displayForm->setObjectName(QStringLiteral("displayForm"));
        displayForm->resize(1195, 794);
        groupBox = new QGroupBox(displayForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 551, 781));
        verticalScrollBar = new QScrollBar(groupBox);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(510, 190, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(displayForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 10, 611, 781));

        retranslateUi(displayForm);

        QMetaObject::connectSlotsByName(displayForm);
    } // setupUi

    void retranslateUi(QWidget *displayForm)
    {
        displayForm->setWindowTitle(QApplication::translate("displayForm", "Form", 0));
        groupBox->setTitle(QApplication::translate("displayForm", "GroupBox", 0));
        groupBox_2->setTitle(QApplication::translate("displayForm", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class displayForm: public Ui_displayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYFORM_H
