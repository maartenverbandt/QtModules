!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

        HEADERS += \
            $$PWD/qmapwidget.h

        SOURCES += \
            $$PWD/qmapwidget.cpp
                        

    FORMS += 

} else {
    message( "Skipping $$PWD: already included" )
}
