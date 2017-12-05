QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleExample
TEMPLATE = app

INCLUDEPATH +=

PROTOCOL = mavlink

DEFINES += QT_NO_PRINTER

SOURCES += main.cpp \
    qexcitationreceiver.cpp

HEADERS  += \ 
    qexcitationreceiver.h

FORMS    +=

include(../../src/qexcitationwidget.pri)
