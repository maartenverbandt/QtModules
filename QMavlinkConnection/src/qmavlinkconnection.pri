!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += serialport bluetooth network

    INCLUDEPATH += $$PWD \
                   /home/maarten/projects/mavlink/build/include/v1.0/microos_messages/mavlink.h

    SOURCES +=  $$PWD/qconnectioncoordinator.cpp \
                $$PWD/qmavlinkconnection.cpp \
                $$PWD/qusbdevicediscoveryagent.cpp \
                $$PWD/qmavlinkconnectioninfodialog.cpp \
                $$PWD/qmavlinkconnectionlogger.cpp
    HEADERS +=  $$PWD/mavlink.h \
                $$PWD/qconnectioncoordinator.h \
                $$PWD/qmavlinkconnection.h \
                $$PWD/qusbdevicediscoveryagent.h \
                $$PWD/qmavlinkconnectioninfodialog.h \
                $$PWD/qmavlinkconnectionlogger.h

    FORMS +=    $$PWD/qmavlinkconnectioninfodialog.ui

    DEFINES += QT_NO_PRINTER
    include(../../QCustomPlot/src/qcustomplot.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS +=

SOURCES +=
