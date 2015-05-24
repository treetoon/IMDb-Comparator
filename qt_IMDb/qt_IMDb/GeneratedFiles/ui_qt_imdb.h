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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_IMDbClass
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QPushButton *browseButton;
    QPushButton *browse_2Button;
    QPushButton *runButton;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *qt_IMDbClass)
    {
        if (qt_IMDbClass->objectName().isEmpty())
            qt_IMDbClass->setObjectName(QStringLiteral("qt_IMDbClass"));
        qt_IMDbClass->resize(400, 250);
        qt_IMDbClass->setMinimumSize(QSize(400, 250));
        qt_IMDbClass->setMaximumSize(QSize(400, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/32x32/Resources/icon/32x32/IMDb-Comparator.ico"), QSize(), QIcon::Normal, QIcon::Off);
        qt_IMDbClass->setWindowIcon(icon);
        actionExit = new QAction(qt_IMDbClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(qt_IMDbClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(qt_IMDbClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(300, 50));
        browseButton = new QPushButton(groupBox);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(295, 40, 75, 21));
        browseButton->setMinimumSize(QSize(75, 21));
        browseButton->setMaximumSize(QSize(75, 21));
        browse_2Button = new QPushButton(groupBox);
        browse_2Button->setObjectName(QStringLiteral("browse_2Button"));
        browse_2Button->setGeometry(QRect(295, 80, 75, 21));
        browse_2Button->setMinimumSize(QSize(75, 21));
        browse_2Button->setMaximumSize(QSize(75, 21));
        runButton = new QPushButton(groupBox);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(141, 141, 100, 21));
        runButton->setMinimumSize(QSize(100, 21));
        runButton->setMaximumSize(QSize(100, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 271, 16));
        label->setMaximumSize(QSize(271, 20));

        verticalLayout->addWidget(groupBox);

        qt_IMDbClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_IMDbClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        qt_IMDbClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_IMDbClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_IMDbClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(qt_IMDbClass);

        QMetaObject::connectSlotsByName(qt_IMDbClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_IMDbClass)
    {
        qt_IMDbClass->setWindowTitle(QApplication::translate("qt_IMDbClass", "IMDb Comparator", 0));
        actionExit->setText(QApplication::translate("qt_IMDbClass", "Exit", 0));
        actionAbout->setText(QApplication::translate("qt_IMDbClass", "About", 0));
        groupBox->setTitle(QApplication::translate("qt_IMDbClass", "Select .csv files", 0));
        browseButton->setText(QApplication::translate("qt_IMDbClass", "Browse...", 0));
        browse_2Button->setText(QApplication::translate("qt_IMDbClass", "Browse...", 0));
        runButton->setText(QApplication::translate("qt_IMDbClass", "Show Lists", 0));
        label->setText(QApplication::translate("qt_IMDbClass", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("qt_IMDbClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("qt_IMDbClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_IMDbClass: public Ui_qt_IMDbClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_IMDB_H
