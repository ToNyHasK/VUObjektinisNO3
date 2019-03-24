cmake_minimum_required(VERSION 3.13)
project(Versija_kuria_keiciam)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Versija_kuria_keiciam
        v1-laikai.cpp
        header.h
        createFilesFunc.cpp)
