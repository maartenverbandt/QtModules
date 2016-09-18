QT += core gui widgets

CONFIG += c++11

TARGET = MapPlot
CONFIG += console app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qmapwidgettester.cpp

include(../../src/qmapwidget.pri)

HEADERS += \
    qmapwidgettester.h
