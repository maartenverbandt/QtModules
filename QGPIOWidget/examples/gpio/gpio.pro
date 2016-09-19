#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T14:31:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gpio
TEMPLATE = app

INCLUDEPATH += $$PWD

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
            $$PWD/mavlink.h

FORMS    += mainwindow.ui

include(../../src/qgpiowidget.pri)
