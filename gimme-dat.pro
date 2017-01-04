#-------------------------------------------------
#
# Project created by QtCreator 2016-12-27T21:32:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gimme-dat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trie.cpp \
    trienode.cpp

HEADERS  += mainwindow.h \
    trie.h \
    trienode.h

FORMS    += mainwindow.ui
