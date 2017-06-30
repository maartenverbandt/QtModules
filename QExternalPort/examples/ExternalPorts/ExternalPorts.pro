#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T11:03:15
#
#-------------------------------------------------

QT       += core gui gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExternalPorts
TEMPLATE = app

INCLUDEPATH += mavlink

SOURCES += main.cpp\
        mainwindow.cpp \
    listener.cpp \
    talker.cpp

HEADERS  += mainwindow.h \
    listener.h \
    talker.h

FORMS    += mainwindow.ui

include(../../src/qexternalport.pri)
