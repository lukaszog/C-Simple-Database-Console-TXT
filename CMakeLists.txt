cmake_minimum_required(VERSION 3.3)
project(CDDB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Model.h Observer.h View.h Controller.h Controller.cpp Model.cpp View.cpp Observer.cpp Work.h Record.h)
add_executable(CDDB ${SOURCE_FILES})