#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T23:50:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_IMDb
TEMPLATE = app


SOURCES += main.cpp\
        qt_imdb.cpp \
    aboutdialog.cpp \
    displayform.cpp \
    GeneratedFiles/Debug/moc_qt_imdb.cpp \
    GeneratedFiles/Release/moc_aboutdialog.cpp \
    GeneratedFiles/Release/moc_displayform.cpp \
    GeneratedFiles/Release/moc_qt_imdb.cpp \
    GeneratedFiles/qrc_qt_imdb.cpp \
    ../../IMDb-Comparator/IMDb-Comparator/Title.cpp \
    ../../IMDb-Comparator/IMDb-Comparator/TitleList.cpp

HEADERS  += qt_imdb.h \
    aboutdialog.h \
    displayform.h \
    GeneratedFiles/ui_aboutdialog.h \
    GeneratedFiles/ui_displayform.h \
    GeneratedFiles/ui_qt_imdb.h \
    ../../IMDb-Comparator/IMDb-Comparator/Title.h \
    ../../IMDb-Comparator/IMDb-Comparator/TitleList.h

FORMS    += qt_imdb.ui \
    aboutdialog.ui \
    displayform.ui

RESOURCES += \
    qt_imdb.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../IMDb-Comparator/release/ -lIMDb-Comparator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../IMDb-Comparator/debug/ -lIMDb-Comparator

INCLUDEPATH += $$PWD/../../IMDb-Comparator/Release
DEPENDPATH += $$PWD/../../IMDb-Comparator/Release

DISTFILES += \
    ../../IMDb-Comparator/IMDb-Comparator/MovieList.csv
