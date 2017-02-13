#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T22:55:26
#
#-------------------------------------------------

QT       += core gui network
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = claraUI
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    claraKeyMap.cpp \
    claraTerminal.cpp \
    globalVariables.cpp \
    fileHandler.cpp \
    logHandler.cpp \
    projectExplorer.cpp \
    uiHandler.cpp \
    claraEditor.cpp \
    claraHelp.cpp \
    LineNumberArea.cpp \
    qtextedithighlighter.cpp

HEADERS  += mainwindow.h \
    claraKeyMap.h \
    claraTerminal.h \
    globalVariables.h \
    fileHandler.h \
    logHandler.h \
    projectExplorer.h \
    uiHandler.h \
    claraEditor.h \
    claraHelp.h \
    LineNumberArea.h \
    qtextedithighlighter.h

FORMS    += mainwindow.ui

RESOURCES += \
    imageResource.qrc
