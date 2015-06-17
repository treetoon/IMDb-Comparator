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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_4;
    QGroupBox *groupBox_1;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView_1;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QCheckBox *checkBox_featureFilms;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox_infoPage_1;
    QLabel *label_numHrs_1;
    QLabel *label_numHrs_1b;
    QLabel *label_numHrs_filter_1;
    QLabel *label_numHrs_filter_1b;
    QGroupBox *groupBox_infoPage_2;
    QLabel *label_numHrs_2;
    QLabel *label_numHrs_2b;
    QLabel *label_numHrs_filter_2;
    QLabel *label_numHrs_filter_2b;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuLoad;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QStringLiteral("mainwindowClass"));
        mainwindowClass->setEnabled(true);
        mainwindowClass->resize(1024, 681);
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
        mainwindowClass->setStyleSheet(QLatin1String("QMainWindow{\n"
"	background-color:#282828;\n"
"}\n"
"\n"
"QMenuBar{\n"
"	background-color:#2d2d2d;\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"	background-color:#2d2d2d;\n"
"	color:#fff;\n"
"}\n"
"\n"
"QMenuBar::item:selected{\n"
"	background: #404040;\n"
"}\n"
"\n"
"QMenu{\n"
"	background-color:#1a1a1a;\n"
"	color:#fff;\n"
"	padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"	background-color:#343434;\n"
"	color:#fff;\n"
"}\n"
"\n"
"QSplitter::handle{\n"
"    \n"
"}\n"
"\n"
"QStatusBar{\n"
"	background-color:#2d2d2d;\n"
"	color:#fff;\n"
"}\n"
"\n"
""));
        mainwindowClass->setTabShape(QTabWidget::Rounded);
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
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFocusPolicy(Qt::TabFocus);
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
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
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
        groupBox_1->setMinimumSize(QSize(25, 0));
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
        groupBox_2->setMinimumSize(QSize(25, 0));
        groupBox_2->setAcceptDrops(true);
        groupBox_2->setFlat(false);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        sizePolicy.setHeightForWidth(tableView_2->sizePolicy().hasHeightForWidth());
        tableView_2->setSizePolicy(sizePolicy);
        tableView_2->setAcceptDrops(true);

        verticalLayout->addWidget(tableView_2);

        splitter_4->addWidget(groupBox_2);

        horizontalLayout->addWidget(splitter_4);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(100, 20));
        comboBox->setMaximumSize(QSize(150, 20));
        comboBox->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(comboBox);

        checkBox_featureFilms = new QCheckBox(tab);
        checkBox_featureFilms->setObjectName(QStringLiteral("checkBox_featureFilms"));
        sizePolicy1.setHeightForWidth(checkBox_featureFilms->sizePolicy().hasHeightForWidth());
        checkBox_featureFilms->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(checkBox_featureFilms);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(0, 100);
        verticalLayout_3->setStretch(1, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        groupBox_infoPage_1 = new QGroupBox(tab_2);
        groupBox_infoPage_1->setObjectName(QStringLiteral("groupBox_infoPage_1"));
        label_numHrs_1 = new QLabel(groupBox_infoPage_1);
        label_numHrs_1->setObjectName(QStringLiteral("label_numHrs_1"));
        label_numHrs_1->setGeometry(QRect(11, 20, 200, 30));
        label_numHrs_1->setMaximumSize(QSize(200, 30));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(28);
        label_numHrs_1->setFont(font);
        label_numHrs_1b = new QLabel(groupBox_infoPage_1);
        label_numHrs_1b->setObjectName(QStringLiteral("label_numHrs_1b"));
        label_numHrs_1b->setGeometry(QRect(11, 50, 150, 15));
        label_numHrs_1b->setMaximumSize(QSize(150, 15));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label_numHrs_1b->setFont(font1);
        label_numHrs_filter_1 = new QLabel(groupBox_infoPage_1);
        label_numHrs_filter_1->setObjectName(QStringLiteral("label_numHrs_filter_1"));
        label_numHrs_filter_1->setGeometry(QRect(10, 70, 250, 30));
        label_numHrs_filter_1->setMaximumSize(QSize(250, 30));
        label_numHrs_filter_1->setFont(font);
        label_numHrs_filter_1b = new QLabel(groupBox_infoPage_1);
        label_numHrs_filter_1b->setObjectName(QStringLiteral("label_numHrs_filter_1b"));
        label_numHrs_filter_1b->setGeometry(QRect(10, 100, 200, 15));
        label_numHrs_filter_1b->setMaximumSize(QSize(200, 15));
        label_numHrs_filter_1b->setFont(font1);
        label_numHrs_1b->raise();
        label_numHrs_1->raise();
        label_numHrs_filter_1->raise();
        label_numHrs_filter_1b->raise();

        horizontalLayout_10->addWidget(groupBox_infoPage_1);

        groupBox_infoPage_2 = new QGroupBox(tab_2);
        groupBox_infoPage_2->setObjectName(QStringLiteral("groupBox_infoPage_2"));
        label_numHrs_2 = new QLabel(groupBox_infoPage_2);
        label_numHrs_2->setObjectName(QStringLiteral("label_numHrs_2"));
        label_numHrs_2->setGeometry(QRect(11, 20, 200, 30));
        label_numHrs_2->setMaximumSize(QSize(200, 30));
        label_numHrs_2->setFont(font);
        label_numHrs_2b = new QLabel(groupBox_infoPage_2);
        label_numHrs_2b->setObjectName(QStringLiteral("label_numHrs_2b"));
        label_numHrs_2b->setGeometry(QRect(11, 50, 150, 15));
        label_numHrs_2b->setMaximumSize(QSize(150, 15));
        label_numHrs_2b->setFont(font1);
        label_numHrs_filter_2 = new QLabel(groupBox_infoPage_2);
        label_numHrs_filter_2->setObjectName(QStringLiteral("label_numHrs_filter_2"));
        label_numHrs_filter_2->setGeometry(QRect(10, 70, 250, 30));
        label_numHrs_filter_2->setMaximumSize(QSize(250, 30));
        label_numHrs_filter_2->setFont(font);
        label_numHrs_filter_2b = new QLabel(groupBox_infoPage_2);
        label_numHrs_filter_2b->setObjectName(QStringLiteral("label_numHrs_filter_2b"));
        label_numHrs_filter_2b->setGeometry(QRect(10, 100, 200, 15));
        label_numHrs_filter_2b->setMaximumSize(QSize(200, 15));
        label_numHrs_filter_2b->setFont(font1);

        horizontalLayout_10->addWidget(groupBox_infoPage_2);


        horizontalLayout_7->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        verticalLayout_2->setStretch(0, 3);

        horizontalLayout_3->addLayout(verticalLayout_2);

        mainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
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
        checkBox_featureFilms->setText(QApplication::translate("mainwindowClass", "Show Only Feature Films", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mainwindowClass", "Film Tables", 0));
        groupBox_infoPage_1->setTitle(QApplication::translate("mainwindowClass", "#1 .csv file", 0));
        label_numHrs_1->setText(QApplication::translate("mainwindowClass", "NUM_HRS", 0));
        label_numHrs_1b->setText(QApplication::translate("mainwindowClass", "Film hours on record", 0));
        label_numHrs_filter_1->setText(QApplication::translate("mainwindowClass", "FILTER_NUM_HRS", 0));
        label_numHrs_filter_1b->setText(QApplication::translate("mainwindowClass", "Film (Filter) hours on record", 0));
        groupBox_infoPage_2->setTitle(QApplication::translate("mainwindowClass", "#2 .csv file", 0));
        label_numHrs_2->setText(QApplication::translate("mainwindowClass", "NUM_HRS_2", 0));
        label_numHrs_2b->setText(QApplication::translate("mainwindowClass", "Film hours on record", 0));
        label_numHrs_filter_2->setText(QApplication::translate("mainwindowClass", "FILTER_NUM_HRS_2", 0));
        label_numHrs_filter_2b->setText(QApplication::translate("mainwindowClass", "Film (Filter) hours on record", 0));
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
