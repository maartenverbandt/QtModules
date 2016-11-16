#-------------------------------------------------
#
# Project created by QtCreator 2014-11-29T14:13:58
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT +=

TARGET = QTrustmasterReader
TEMPLATE = app
CONFIG += console

SOURCES += main.cpp \
    qcontrollerdevicereader.cpp

HEADERS += \
    qcontrollerdevicereader.h

include(../src/qcontrollerdevice.pri)
