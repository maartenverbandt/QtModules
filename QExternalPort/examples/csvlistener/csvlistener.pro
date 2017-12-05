#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T16:49:01
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csvlistener
TEMPLATE = app

PROTOCOL = mavlink
DEFINES += QT_NO_PRINTER

SOURCES += main.cpp\
        #mainwindow.cpp

HEADERS  += #mainwindow.h

FORMS    += #mainwindow.ui

include(../../src/qexternalport.pri)
