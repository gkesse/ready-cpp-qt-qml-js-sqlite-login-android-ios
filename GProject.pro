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

INCLUDEPATH +=\
    $$PWD/src/include \
    
HEADERS +=\
    
SOURCES +=\
    $$PWD/src/main.cpp \
    $$PWD/src/manager/GManager.cpp \
