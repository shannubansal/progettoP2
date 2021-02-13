QT -= core gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    xmlwriter.cpp \
    vacation.cpp \
    flat.cpp \
    hotel.cpp \
    camping.cpp \
    pitch.cpp \
    bungalow.cpp \
    model.cpp \
    controller.cpp \
    mainwindow.cpp \
    combovacation.cpp \
    vacationlist.cpp \
    vacationlistitem.cpp \
    addvwindow.cpp \
    modvwindow.cpp \
    disvwindow.cpp \
    writer.cpp \
    filemanager.cpp

HEADERS += \
    writer.h \
    xmlwriter.h \
    reader.h \
    container.h \
    deepPtr.h \
    vacation.h \
    flat.h \
    hotel.h \
    camping.h \
    pitch.h \
    bungalow.h \
    model.h \
    controller.h \
    mainwindow.h \
    combovacation.h \
    vacationlist.h \
    vacationlistitem.h \
    addvwindow.h \
    modvwindow.h \
    disvwindow.h \
    filemanager.h
