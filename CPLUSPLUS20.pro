TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++20 -fmodules-ts -fcoroutines #-xc++-system-header iostream#-fmodule-header

SOURCES += \
        CoroutineHead.cpp \
        CoroutineImpl.cpp \
        ImplTest.cpp \
        Test.cpp \
        main.cpp
