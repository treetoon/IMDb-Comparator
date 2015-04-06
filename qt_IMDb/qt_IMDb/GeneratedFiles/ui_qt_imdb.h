/********************************************************************************
** Form generated from reading UI file 'qt_imdb.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_IMDB_H
#define UI_QT_IMDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_IMDbClass
{
public:
    QAction *actionSep;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menuButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_IMDbClass)
    {
        if (qt_IMDbClass->objectName().isEmpty())
            qt_IMDbClass->setObjectName(QStringLiteral("qt_IMDbClass"));
        qt_IMDbClass->resize(600, 400);
        actionSep = new QAction(qt_IMDbClass);
        actionSep->setObjectName(QStringLiteral("actionSep"));
        centralWidget = new QWidget(qt_IMDbClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 190, 75, 23));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(10, 20, 256, 192));
        qt_IMDbClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_IMDbClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuButton = new QMenu(menuBar);
        menuButton->setObjectName(QStringLiteral("menuButton"));
        qt_IMDbClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_IMDbClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_IMDbClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_IMDbClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_IMDbClass->setStatusBar(statusBar);

        menuBar->addAction(menuButton->menuAction());
        menuButton->addAction(actionSep);

        retranslateUi(qt_IMDbClass);

        QMetaObject::connectSlotsByName(qt_IMDbClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_IMDbClass)
    {
        qt_IMDbClass->setWindowTitle(QApplication::translate("qt_IMDbClass", "qt_IMDb", 0));
        actionSep->setText(QApplication::translate("qt_IMDbClass", "sep", 0));
        pushButton->setText(QApplication::translate("qt_IMDbClass", "PushButton", 0));
        menuButton->setTitle(QApplication::translate("qt_IMDbClass", "button", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_IMDbClass: public Ui_qt_IMDbClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_IMDB_H
