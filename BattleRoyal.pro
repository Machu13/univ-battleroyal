TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Nos_fichiers/config.cpp \
    Nos_fichiers/game.cpp \
    Nos_fichiers/screen.cpp \
    Nos_fichiers/gridmanager.cpp \
    Nos_fichiers/menu.cpp \
    Nos_fichiers/ioutils.cpp \
    Nos_fichiers/score.cpp
    
DISTFILES += \
    Nos_fichiers/config.yml \
    Nos_fichiers/bronx.txt \
    Nos_fichiers/score.txt

HEADERS += \
    Nos_fichiers/config.h \
    Nos_fichiers/type.h \
    Nos_fichiers/game.h \
    Nos_fichiers/screen.h \
    Nos_fichiers/gridmanager.h \
    Nos_fichiers/menu.h \
    Nos_fichiers/ioutils.h \
    Nos_fichiers/score.h
