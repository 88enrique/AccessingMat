TEMPLATE = app
CONFIG += console
CONFIG -= qt

INCLUDEPATH += /usr/local/opencv/include/
LIBS += -L/usr/local/opencv/lib -lopencv_core -lopencv_imgproc -lopencv_highgui

SOURCES += main.cpp

