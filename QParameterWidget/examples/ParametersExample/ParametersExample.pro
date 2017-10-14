QT       += core gui gamepad
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += mavlink
INCLUDEPATH += $$PWD

HEADERS += \

SOURCES += \
    main.cpp

include(../../src/qparameterwidget.pri)
