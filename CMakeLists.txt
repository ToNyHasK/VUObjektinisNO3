cmake_minimum_required(VERSION 3.13)
project(Versija_kuria_keiciam)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")

include_directories(.)

add_executable(Versija_kuria_keiciam
        createFilesFunc.cpp
        functions.h
        header.h
        v1-laikai.cpp
        functions.h
        createFilesFunc.cpp)