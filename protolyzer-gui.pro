TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    analyzesignal.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    routines.js

HEADERS += \
    analyzesignal.h
