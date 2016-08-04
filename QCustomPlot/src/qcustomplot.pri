!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += printsupport

    INCLUDEPATH += $$PWD

    SOURCES +=  $$PWD/qcustomplot.cpp \
                $$PWD/qrunningplot.cpp
    HEADERS +=  $$PWD/qcustomplot.h \
                $$PWD/qrunningplot.h

    FORMS +=
} else {
    message( "Skipping $$PWD: already included" )
}
