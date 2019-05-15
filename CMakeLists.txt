cmake_minimum_required(VERSION 3.13)
project(Versija_kuria_keiciam)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

include_directories(.)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
add_executable(Versija_kuria_keiciam
        createFilesFunc.cpp
        functions.h
        header.h
        v1-laikai.cpp)
target_link_libraries(Versija_kuria_keiciam gtest gtest_main)