#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T07:15:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += silent static plugin
TARGET   = kaffee_automat
DESTDIR  = ./.
TEMPLATE = lib

SOURCES += main.cpp\
        MainWindow.cpp \
    CoffeeMachine.cpp \
    DragEventFilter.cpp \
    DropEventFilter.cpp \
    TraficAnalysis.cpp

HEADERS  += MainWindow.h \
            automat.h \
    CoffeeMachine.h \
    DragEventFilter.h \
    DropEventFilter.h \
    MousePressForwarding.h \
    AutomatTypes.h \
    TraficAnalysis.h

FORMS    += MainWindow.ui \
    CoffeeMachine.ui \
    TraficAnalysis.ui

unix {
    OBJECTS_DIR   = .build
    UI_DIR        = .build
    MOC_DIR       = .build
    RCC_DIR       = .build
}

include(../checker/checker.pri)

RESOURCES += \
    resource.qrc
