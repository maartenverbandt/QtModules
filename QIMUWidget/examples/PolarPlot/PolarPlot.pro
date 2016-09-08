QT += core gui widgets

CONFIG += c++11

TARGET = PolarPlot
CONFIG += console app_bundle

TEMPLATE = app

SOURCES += main.cpp

DEFINES += QT_NO_PRINTER

include(../../src/qimuwidget.pri)
