TEMPLATE = app
TARGET = clock

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    clockscreen.cpp \
    main.cpp

HEADERS += \
    clockscreen.h
