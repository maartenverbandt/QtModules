!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network

    INCLUDEPATH += $$PWD \
                   $$PWD/Commands \
                   $$PWD/Commands/CSV \
                   $$PWD/Commands/UDP \
                   $$PWD/Commands/Gamepad \

        HEADERS += \
            $$PWD/Commands/qdataportinterface.h \
            $$PWD/Commands/qexternalportdialog.h \
            $$PWD/Commands/qinputwidget.h \
            $$PWD/Commands/CSV/qcsvreader.h\
            $$PWD/Commands/CSV/qcsvreaderwidget.h \
            $$PWD/Commands/CSV/qgpiocsvreader.h \
            $$PWD/Commands/CSV/qpositioncmdcsvreader.h \
            $$PWD/Commands/UDP/qtudpreader.h \
            $$PWD/Commands/UDP/qudpreader.h \
            $$PWD/Commands/UDP/qudpreaderwidget.h \
            $$PWD/Commands/Gamepad/qgamepadinputwidget.h \
            $$PWD/Commands/Gamepad/qgamepadbutton.h \
            $$PWD/Commands/Gamepad/qvelocitygamepadcommand.h \
            $$PWD/Commands/Gamepad/qcommandmapwidget.h \
            $$PWD/Commands/Gamepad/qgamepadcommand.h \
            $$PWD/Commands/Gamepad/qcommand.h \

        SOURCES += \
            $$PWD/Commands/qinputwidget.cpp \
            $$PWD/Commands/qexternalportdialog.cpp \
            $$PWD/Commands/CSV/qcsvreader.cpp \
            $$PWD/Commands/CSV/qcsvreaderwidget.cpp \
            $$PWD/Commands/CSV/qgpiocsvreader.cpp \
            $$PWD/Commands/CSV/qpositioncmdcsvreader.cpp \
            $$PWD/Commands/UDP/qudpreader.cpp \
            $$PWD/Commands/UDP/qudpreaderwidget.cpp \
            $$PWD/Commands/Gamepad/qgamepadinputwidget.cpp \
            $$PWD/Commands/Gamepad/qgamepadbutton.cpp \
            $$PWD/Commands/Gamepad/qvelocitygamepadcommand.cpp \
            $$PWD/Commands/Gamepad/qcommandmapwidget.cpp \
            $$PWD/Commands/Gamepad/qgamepadcommand.cpp \
            $$PWD/Commands/Gamepad/qcommand.cpp \
                        

    FORMS += $$PWD/Commands/CSV/qcsvreaderwidget.ui\
             $$PWD/Commands/UDP/qudpportwidget.ui \
             $$PWD/Commands/Gamepad/qcommandmapwidget.ui \

include(../../QMavlinkConnection/src/qmavlinkconnection.pri)

} else {
    message( "Skipping $$PWD: already included" )
}
