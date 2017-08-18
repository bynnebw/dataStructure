cmake_minimum_required(VERSION 3.7)
project(Graph_Basic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Component.h
        DenseGraph.h
        main.cpp
        main1.cpp
        main2.cpp
        ReadGraph.h
        SparseGraph.h)

add_executable(Graph_Basic ${SOURCE_FILES})