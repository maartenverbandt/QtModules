QT += core
QT += gui

CONFIG += c++11

TARGET = QMavlinkSearch
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

include(../../src/qmavlinkconnection.pri)
