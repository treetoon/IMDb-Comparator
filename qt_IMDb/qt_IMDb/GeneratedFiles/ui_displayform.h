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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displayForm
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
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
        verticalLayout = new QVBoxLayout(displayForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_4 = new QSplitter(displayForm);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setChildrenCollapsible(false);
        groupBox = new QGroupBox(splitter_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(100, 0));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);

        horizontalLayout_2->addWidget(tableView);

        splitter_4->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(100, 0));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        sizePolicy.setHeightForWidth(tableView_2->sizePolicy().hasHeightForWidth());
        tableView_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(tableView_2);

        splitter_4->addWidget(groupBox_2);

        verticalLayout->addWidget(splitter_4);

        comboBox = new QComboBox(displayForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(250, 16777215));

        verticalLayout->addWidget(comboBox);


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
