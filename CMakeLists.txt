cmake_minimum_required(VERSION 3.5)
project(cab301_assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/experiment.cpp src/experiment.h)
add_executable(cab301_assignment2 ${SOURCE_FILES})