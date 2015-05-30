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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *runButton;
    QLineEdit *browse_line_1;
    QPushButton *browseButton;
    QLineEdit *browse_line_2;
    QPushButton *browse_2Button;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *qt_IMDbClass)
    {
        if (qt_IMDbClass->objectName().isEmpty())
            qt_IMDbClass->setObjectName(QStringLiteral("qt_IMDbClass"));
        qt_IMDbClass->resize(400, 200);
        qt_IMDbClass->setMinimumSize(QSize(400, 200));
        qt_IMDbClass->setMaximumSize(QSize(400, 200));
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
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 50));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(0);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        runButton = new QPushButton(frame_2);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setMinimumSize(QSize(100, 21));
        runButton->setMaximumSize(QSize(100, 21));

        gridLayout_3->addWidget(runButton, 0, 0, 1, 1);


        gridLayout->addWidget(frame_2, 2, 0, 1, 2);

        browse_line_1 = new QLineEdit(groupBox);
        browse_line_1->setObjectName(QStringLiteral("browse_line_1"));
        browse_line_1->setReadOnly(true);

        gridLayout->addWidget(browse_line_1, 0, 0, 1, 1);

        browseButton = new QPushButton(groupBox);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setMinimumSize(QSize(75, 21));
        browseButton->setMaximumSize(QSize(75, 21));

        gridLayout->addWidget(browseButton, 0, 1, 1, 1);

        browse_line_2 = new QLineEdit(groupBox);
        browse_line_2->setObjectName(QStringLiteral("browse_line_2"));
        browse_line_2->setReadOnly(true);

        gridLayout->addWidget(browse_line_2, 1, 0, 1, 1);

        browse_2Button = new QPushButton(groupBox);
        browse_2Button->setObjectName(QStringLiteral("browse_2Button"));
        browse_2Button->setMinimumSize(QSize(75, 21));
        browse_2Button->setMaximumSize(QSize(75, 21));

        gridLayout->addWidget(browse_2Button, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        qt_IMDbClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_IMDbClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        qt_IMDbClass->setMenuBar(menuBar);

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
        runButton->setText(QApplication::translate("qt_IMDbClass", "Show Lists", 0));
#ifndef QT_NO_TOOLTIP
        browse_line_1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        browse_line_1->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        browse_line_1->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        browseButton->setText(QApplication::translate("qt_IMDbClass", "Browse...", 0));
        browse_2Button->setText(QApplication::translate("qt_IMDbClass", "Browse...", 0));
        menuFile->setTitle(QApplication::translate("qt_IMDbClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("qt_IMDbClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_IMDbClass: public Ui_qt_IMDbClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_IMDB_H
