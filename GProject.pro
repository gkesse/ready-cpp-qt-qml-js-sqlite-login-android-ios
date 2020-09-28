TEMPLATE = app
TARGET = gp_qt
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console release gnu++11
QT += widgets
RESOURCES += resources.qrc

GRLIB = C:/Users/Admin/Downloads/Programs/ReadyLib/dev

include($$GRLIB/qtawesome/4.7.0/mingw/QtAwesome.pri)

INCLUDEPATH +=\
    $$PWD/src/include \
    
HEADERS +=\
    $$PWD/src/include/GWindow.h \
    $$PWD/src/include/GPageAdmin.h \
    $$PWD/src/include/GTitleBar.h \
    $$PWD/src/include/GMenuIcon.h \
    
SOURCES +=\
    $$PWD/src/main.cpp \
    $$PWD/src/manager/GManager.cpp \
    $$PWD/src/manager/GWindow.cpp \
    $$PWD/src/manager/GPageAdmin.cpp \
    $$PWD/src/manager/GTitleBar.cpp \
    $$PWD/src/manager/GMenuIcon.cpp \
