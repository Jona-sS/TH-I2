
TEMPLATE = app
TARGET = refdatamaker
DESTDIR = ./.
DEPENDPATH += .
INCLUDEPATH += .

SOURCES +=  $$PWD/refdatamaker.cpp \
            $$PWD/Input.cpp \
            $$PWD/Output.cpp \
            $$PWD/Transaction.cpp \
            $$PWD/TransactionList.cpp \

HEADERS +=  \
            $$PWD/Input.h \
            $$PWD/Output.h \
            $$PWD/Transaction.h \
            $$PWD/TransactionList.h \

# add automat to build
DEPENDPATH  += ../app
INCLUDEPATH += ../app
SOURCES     += ../app/automat.c
HEADERS     += ../app/automat.h
