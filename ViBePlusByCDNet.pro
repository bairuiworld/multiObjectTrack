TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    VIBE.cpp \
    BackgroundSubtract.cpp \
    Comparator.cpp \
    VideoFolder.cpp \
    Method.cpp \
    MyMethod.cpp \
    Result.cpp

INCLUDEPATH += /usr/local/include/opencv \
                /usr/local/include
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_flann  \

LIBS += /home/xiongqiang/workspace/ViBePlusByCDNet/jsoncpp.so


HEADERS += \
    VIBE.h \
    BackgroundSubtract.h \
    OpencvInclude.h \
    Comparator.h \
    types.h \
    VideoFolder.h \
    Method.h \
    MyMethod.h \
    Result.h

