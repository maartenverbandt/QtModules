QT += core gui widgets

CONFIG += c++11

TARGET = RunningPolarPlot
CONFIG += console app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qrunningpolarplottester.cpp

DEFINES += QT_NO_PRINTER

include(../../src/qpolarplot.pri)

HEADERS += \
    qrunningpolarplottester.h
