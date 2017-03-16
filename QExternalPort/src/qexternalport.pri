!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network

    INCLUDEPATH += $$PWD \
                   $$PWD/CSV \
                   $$PWD/UDP \
                   $$PWD/Gamepad

        HEADERS += \
            $$PWD/qdataportinterface.h \
            $$PWD/qexternalportdialog.h \
            $$PWD/qinputwidget.h \
            $$PWD/CSV/qcsvreader.h\
            $$PWD/CSV/qcsvreaderwidget.h \
            $$PWD/CSV/qgpiocsvreader.h \
            $$PWD/CSV/qpositioncmdcsvreader.h \
            $$PWD/UDP/qtudpreader.h \
            $$PWD/UDP/qudpreader.h \
            $$PWD/UDP/qudpreaderwidget.h \
            $$PWD/Gamepad/qgamepadinputwidget.h \
            $$PWD/Gamepad/qgamepadbutton.h \
            $$PWD/Gamepad/qvelocitygamepadcommand.h

        SOURCES += \
            $$PWD/qinputwidget.cpp \
            $$PWD/qexternalportdialog.cpp \
            $$PWD/CSV/qcsvreader.cpp \
            $$PWD/CSV/qcsvreaderwidget.cpp \
            $$PWD/CSV/qgpiocsvreader.cpp \
            $$PWD/CSV/qpositioncmdcsvreader.cpp \
            $$PWD/UDP/qudpreader.cpp \
            $$PWD/UDP/qudpreaderwidget.cpp \
            $$PWD/Gamepad/qgamepadinputwidget.cpp \
            $$PWD/Gamepad/qgamepadbutton.cpp \
            $$PWD/Gamepad/qvelocitygamepadcommand.cpp
                        

    FORMS += $$PWD/CSV/qcsvreaderwidget.ui\
             $$PWD/UDP/qudpportwidget.ui

include(../../QMavlinkConnection/src/qmavlinkconnection.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

FORMS += \
    $$PWD/Gamepad/qcommandmapwidget.ui

HEADERS += \
    $$PWD/Gamepad/qcommandmap.h \
    $$PWD/Gamepad/qcommandmapwidget.h

SOURCES += \
    $$PWD/Gamepad/qcommandmap.cpp \
    $$PWD/Gamepad/qcommandmapwidget.cpp
