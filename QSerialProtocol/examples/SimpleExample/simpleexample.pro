QT       += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

PROTOCOL = mavlink
INCLUDEPATH += $$PWD

DEFINES += QT_NO_PRINTER

HEADERS += \
    qheartbeatchecker.h

SOURCES += \
    main.cpp \
    qheartbeatchecker.cpp

include(../../src/qserialprotocol.pri)
