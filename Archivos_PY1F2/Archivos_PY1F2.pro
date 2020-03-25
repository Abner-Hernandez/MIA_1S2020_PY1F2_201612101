TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        driver.cpp \
        main.cpp \
        methods.cpp \
        parser.tab.cc \
        scanner.cpp

DISTFILES += \
    entrada.txt

HEADERS += \
    driver.h \
    lexico.l \
    location.hh \
    parser.tab.hh \
    parser.yy \
    position.hh \
    stack.hh
