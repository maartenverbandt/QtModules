#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T11:03:15
#
#-------------------------------------------------

QT       += core gui gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GamepadExample
TEMPLATE = app

PROTOCOL = mavlink
DEFINES += QT_NO_PRINTER

SOURCES +=  main.cpp\
            listener.cpp

HEADERS  += listener.h

FORMS    += 

include(../../src/qcommandwidget.pri)
