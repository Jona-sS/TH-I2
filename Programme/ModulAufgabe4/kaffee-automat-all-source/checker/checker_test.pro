
TEMPLATE = app
TARGET = checker_test
DESTDIR = ./.
DEPENDPATH += .
INCLUDEPATH += .

include($$PWD/checker.pri)

SOURCES += checker_test.c

# add automat to build
DEPENDPATH  += ../app
INCLUDEPATH += ../app
SOURCES     += ../app/automat.c
HEADERS     += ../app/automat.h
