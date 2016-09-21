#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T12:07:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csvreader
TEMPLATE = app


SOURCES += main.cpp\
        qgpioinputdialogtester.cpp

HEADERS  += qgpioinputdialogtester.h
#            $$PWD/mavlink.h

FORMS    += qgpioinputdialogtester.ui

include(../../src/qgpiowidget.pri)
