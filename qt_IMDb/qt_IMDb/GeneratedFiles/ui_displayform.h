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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displayForm
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView_2;
    QComboBox *comboBox;

    void setupUi(QWidget *displayForm)
    {
        if (displayForm->objectName().isEmpty())
            displayForm->setObjectName(QStringLiteral("displayForm"));
        displayForm->resize(1221, 634);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayForm->sizePolicy().hasHeightForWidth());
        displayForm->setSizePolicy(sizePolicy);
        displayForm->setMinimumSize(QSize(200, 100));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/32x32/Resources/icon/32x32/IMDb-Comparator.ico"), QSize(), QIcon::Normal, QIcon::Off);
        displayForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(displayForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(displayForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(tableView);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(displayForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        sizePolicy.setHeightForWidth(tableView_2->sizePolicy().hasHeightForWidth());
        tableView_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(tableView_2);

        tableView_2->raise();
        tableView->raise();

        gridLayout->addWidget(groupBox_2, 0, 5, 1, 1);

        comboBox = new QComboBox(displayForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        groupBox->raise();
        groupBox_2->raise();
        tableView->raise();
        tableView_2->raise();
        comboBox->raise();

        retranslateUi(displayForm);

        QMetaObject::connectSlotsByName(displayForm);
    } // setupUi

    void retranslateUi(QWidget *displayForm)
    {
        displayForm->setWindowTitle(QApplication::translate("displayForm", "Form", 0));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox->setTitle(QApplication::translate("displayForm", "#1 .csv file", 0));
        groupBox_2->setTitle(QApplication::translate("displayForm", "#2 .csv file", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("displayForm", "No Sorting", 0)
         << QApplication::translate("displayForm", "Remove Duplicates", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class displayForm: public Ui_displayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYFORM_H
