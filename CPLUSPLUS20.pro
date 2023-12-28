TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++20 -fmodules-ts #-fmodule-header

SOURCES += \
        ImplTest.cpp \
        Test.cpp \
        main.cpp
