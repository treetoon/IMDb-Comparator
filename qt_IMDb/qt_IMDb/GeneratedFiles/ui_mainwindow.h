/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionLoad_File_1;
    QAction *actionLoad_File_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_4;
    QGroupBox *groupBox_1;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView_1;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView_2;
    QComboBox *comboBox;
    QWidget *tab_2;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuLoad;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QStringLiteral("mainwindowClass"));
        mainwindowClass->setEnabled(true);
        mainwindowClass->resize(1024, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainwindowClass->sizePolicy().hasHeightForWidth());
        mainwindowClass->setSizePolicy(sizePolicy);
        mainwindowClass->setMinimumSize(QSize(300, 200));
        mainwindowClass->setMaximumSize(QSize(16777215, 16777215));
        mainwindowClass->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/32x32/Resources/icon/32x32/IMDb-Comparator.ico"), QSize(), QIcon::Normal, QIcon::Off);
        mainwindowClass->setWindowIcon(icon);
        actionExit = new QAction(mainwindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(mainwindowClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHelp = new QAction(mainwindowClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionLoad_File_1 = new QAction(mainwindowClass);
        actionLoad_File_1->setObjectName(QStringLiteral("actionLoad_File_1"));
        actionLoad_File_2 = new QAction(mainwindowClass);
        actionLoad_File_2->setObjectName(QStringLiteral("actionLoad_File_2"));
        centralWidget = new QWidget(mainwindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAcceptDrops(true);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter_4 = new QSplitter(tab);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setFrameShape(QFrame::NoFrame);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setOpaqueResize(true);
        splitter_4->setHandleWidth(4);
        splitter_4->setChildrenCollapsible(false);
        groupBox_1 = new QGroupBox(splitter_4);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setEnabled(true);
        sizePolicy.setHeightForWidth(groupBox_1->sizePolicy().hasHeightForWidth());
        groupBox_1->setSizePolicy(sizePolicy);
        groupBox_1->setMinimumSize(QSize(100, 0));
        groupBox_1->setAcceptDrops(true);
        groupBox_1->setStyleSheet(QStringLiteral(""));
        groupBox_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_1->setFlat(false);
        groupBox_1->setCheckable(false);
        horizontalLayout_2 = new QHBoxLayout(groupBox_1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView_1 = new QTableView(groupBox_1);
        tableView_1->setObjectName(QStringLiteral("tableView_1"));
        sizePolicy.setHeightForWidth(tableView_1->sizePolicy().hasHeightForWidth());
        tableView_1->setSizePolicy(sizePolicy);
        tableView_1->setAcceptDrops(true);
        tableView_1->setFrameShape(QFrame::StyledPanel);
        tableView_1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableView_1->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_1->verticalHeader()->setCascadingSectionResizes(false);

        horizontalLayout_2->addWidget(tableView_1);

        splitter_4->addWidget(groupBox_1);
        groupBox_2 = new QGroupBox(splitter_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(100, 0));
        groupBox_2->setAcceptDrops(true);
        groupBox_2->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        sizePolicy.setHeightForWidth(tableView_2->sizePolicy().hasHeightForWidth());
        tableView_2->setSizePolicy(sizePolicy);
        tableView_2->setAcceptDrops(true);

        horizontalLayout->addWidget(tableView_2);

        splitter_4->addWidget(groupBox_2);

        verticalLayout_2->addWidget(splitter_4);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(200, 20));
        comboBox->setMaximumSize(QSize(200, 20));
        comboBox->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(comboBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 270, 250, 15));
        label_2->setMaximumSize(QSize(250, 15));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 111, 250, 15));
        label->setMaximumSize(QSize(250, 15));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        mainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 18));
        menuBar->setAcceptDrops(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setAcceptDrops(false);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setAcceptDrops(false);
        menuLoad = new QMenu(menuBar);
        menuLoad->setObjectName(QStringLiteral("menuLoad"));
        menuLoad->setAcceptDrops(false);
        mainwindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLoad->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);
        menuLoad->addAction(actionLoad_File_1);
        menuLoad->addAction(actionLoad_File_2);

        retranslateUi(mainwindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QApplication::translate("mainwindowClass", "IMDb Comparator", 0));
        actionExit->setText(QApplication::translate("mainwindowClass", "Exit", 0));
        actionAbout->setText(QApplication::translate("mainwindowClass", "About", 0));
        actionHelp->setText(QApplication::translate("mainwindowClass", "Help", 0));
        actionLoad_File_1->setText(QApplication::translate("mainwindowClass", "Load File #1", 0));
        actionLoad_File_2->setText(QApplication::translate("mainwindowClass", "Load File #2", 0));
#ifndef QT_NO_TOOLTIP
        groupBox_1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_1->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox_1->setTitle(QApplication::translate("mainwindowClass", "#1 .csv file", 0));
        groupBox_2->setTitle(QApplication::translate("mainwindowClass", "#2 .csv file", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("mainwindowClass", "Show All", 0)
         << QApplication::translate("mainwindowClass", "Remove Duplicates", 0)
         << QApplication::translate("mainwindowClass", "Only Show Duplicates", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mainwindowClass", "Film Tables", 0));
        label_2->setText(QApplication::translate("mainwindowClass", "label_2", 0));
        label->setText(QApplication::translate("mainwindowClass", "label", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("mainwindowClass", "Information", 0));
        menuFile->setTitle(QApplication::translate("mainwindowClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("mainwindowClass", "Help", 0));
        menuLoad->setTitle(QApplication::translate("mainwindowClass", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
