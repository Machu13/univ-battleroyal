TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    config.cpp \
    game.cpp \
    screen.cpp \
    gridmanager.cpp \
    menu.cpp \
    ioutils.cpp

HEADERS += \
    config.h \
    type.h \
    game.h \
    screen.h \
    gridmanager.h \
    ioutils.h
