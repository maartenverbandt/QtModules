!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network gamepad

    INCLUDEPATH += $$PWD \
                   $$PWD/CSV \
                   $$PWD/UDP \
                   $$PWD/Gamepad

        HEADERS += \
            $$PWD/qcommandwidget.h \
            $$PWD/CSV/qcsvreader.h\
            $$PWD/CSV/qcsvreaderwidget.h \
            $$PWD/UDP/qudpreader.h \
            $$PWD/UDP/qudpreaderwidget.h \
            $$PWD/Gamepad/qgamepadbutton.h \
            $$PWD/Gamepad/qvelocitygamepadcommand.h \
            $$PWD/Gamepad/qcommandmapwidget.h \
            $$PWD/Gamepad/qgamepadcommand.h \
            $$PWD/Gamepad/qcommand.h

        SOURCES += \
            $$PWD/qcommandwidget.cpp \
            $$PWD/CSV/qcsvreader.cpp \
            $$PWD/CSV/qcsvreaderwidget.cpp \
            $$PWD/UDP/qudpreader.cpp \
            $$PWD/UDP/qudpreaderwidget.cpp \
            $$PWD/Gamepad/qgamepadbutton.cpp \
            $$PWD/Gamepad/qvelocitygamepadcommand.cpp \
            $$PWD/Gamepad/qcommandmapwidget.cpp \
            $$PWD/Gamepad/qgamepadcommand.cpp \
            $$PWD/Gamepad/qcommand.cpp
                        

    FORMS += $$PWD/CSV/qcsvreaderwidget.ui\
             $$PWD/UDP/qudpportwidget.ui \
             $$PWD/Gamepad/qcommandmapwidget.ui

include(../../QSerialProtocol/src/qserialprotocol.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/Gamepad/qcommandgamepadwidget.h \
    $$PWD/CSV/qcsvcommanddatanodewidget.h \
    $$PWD/CSV/qgpiocsvcommand.h \
    $$PWD/CSV/qpositioncmdcsvcommand.h \
    $$PWD/UDP/qtypeudpcommand.h \
    $$PWD/qtypecommandwidget.h \
    $$PWD/qtypecommandinterface.h

SOURCES += \
    $$PWD/Gamepad/qcommandgamepadwidget.cpp \
    $$PWD/CSV/qcsvcommanddatanodewidget.cpp \
    $$PWD/qtypecommandwidget.cpp \
    $$PWD/CSV/qgpiocsvcommand.cpp \
    $$PWD/CSV/qpositioncmdcsvcommand.cpp
