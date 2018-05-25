#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T18:09:07
#
#-------------------------------------------------

QT       += core gui \
            multimedia \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ant_hill_reborn
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    menu.cpp \
    enemie.cpp \
    xwing.cpp \
    game.cpp \
    base.cpp \
    destroyer.cpp \
    debris.cpp \
    chemin.cpp \
    enemie2.cpp \
    destroyer_base.cpp \
    score.cpp

HEADERS += \
    menu.h \
    enemie.h \
    xwing.h \
    game.h \
    base.h \
    destroyer.h \
    debris.h \
    chemin.h \
    enemie2.h \
    destroyer_base.h \
    score.h

RESOURCES += \
    res.qrc

DISTFILES += \
    Ressources/xwing_2.png
