TEMPLATE = app
TARGET = rdv_qt
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console debug gnu++11
QT += widgets

QMAKE_CXXFLAGS +=\
    -Wno-unused-parameter \
    -Wno-deprecated-declarations \

GSRC = ../src

INCLUDEPATH +=\
    $$GSRC \
	/usr/include \
	/usr/local/include \
	/usr/include/libxml2 \

LIBS +=\
    -lxml2 \
    
SOURCES +=\
    $$files($$GSRC/*.cpp) \
    
HEADERS +=\
    $$files($$GSRC/*.h) \

FORMS +=\
    $$files($$GSRC/*.ui) \
