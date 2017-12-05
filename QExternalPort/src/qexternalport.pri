!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network gamepad

    INCLUDEPATH += $$PWD \
                   $$PWD/CSV \
                   $$PWD/UDP \
                   $$PWD/Gamepad

        HEADERS += \
            $$PWD/qdataportinterface.h \
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

include(../../QSerialProtocol/src/qserialprotocol.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

FORMS += \
    $$PWD/Gamepad/qcommandmapwidget.ui

HEADERS += \
    $$PWD/Gamepad/qcommandmapwidget.h \
    $$PWD/Gamepad/qgamepadcommand.h \
    $$PWD/Gamepad/qcommand.h

SOURCES += \
    $$PWD/Gamepad/qcommandmapwidget.cpp \
    $$PWD/Gamepad/qgamepadcommand.cpp \
    $$PWD/Gamepad/qcommand.cpp

HEADERS += \
    $$PWD/CSV/qcsvreaderdatanodewidget.h \
    $$PWD/qcommandportwidget.h

SOURCES += \
    $$PWD/CSV/qcsvreaderdatanodewidget.cpp \
    $$PWD/qcommandportwidget.cpp
