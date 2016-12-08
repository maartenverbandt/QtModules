!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

        HEADERS += \
            $$PWD/qmapwidget.h\
			$$PWD/qpainterelement.h \
			$$PWD/qrobotelement.h

        SOURCES += \
            $$PWD/qmapwidget.cpp\
			$$PWD/qpainterelement.cpp \
			$$PWD/qrobotelement.cpp
                        

    FORMS += 

} else {
    message( "Skipping $$PWD: already included" )
}
