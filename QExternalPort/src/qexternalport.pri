!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network

    INCLUDEPATH += $$PWD

        HEADERS += \
            $$PWD/qcsvreader.h\
            $$PWD/qcsvreaderwidget.h \
            $$PWD/qdataportinterface.h \
            $$PWD/qgpiocsvreader.h \
            $$PWD/qpositioncmdcsvreader.h \
            $$PWD/qinputwidget.h \
            $$PWD/qtudpreader.h \
            $$PWD/qudpreader.h \
            $$PWD/qudpreaderwidget.h \
            $$PWD/qexternalportdialog.h

        SOURCES += \
            $$PWD/qcsvreader.cpp \
            $$PWD/qcsvreaderwidget.cpp \
            $$PWD/qgpiocsvreader.cpp \
            $$PWD/qpositioncmdcsvreader.cpp \
            $$PWD/qinputwidget.cpp \
            $$PWD/qudpreader.cpp \
            $$PWD/qudpreaderwidget.cpp \
            $$PWD/qexternalportdialog.cpp
                        

    FORMS += $$PWD/qcsvreaderwidget.ui\
             $$PWD/qudpportwidget.ui

include(../../QMavlinkConnection/src/qmavlinkconnection.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/qgamepadinputwidget.h \
    $$PWD/qgamepadbutton.h \
    $$PWD/qconfiguredgamepad.h \
    $$PWD/qgamepadcommand.h \
    $$PWD/qvelocitygamepadcommand.h

SOURCES += \
    $$PWD/qgamepadinputwidget.cpp \
    $$PWD/qgamepadbutton.cpp \
    $$PWD/qconfiguredgamepad.cpp \
    $$PWD/qgamepadcommand.cpp \
    $$PWD/qvelocitygamepadcommand.cpp
