cmake_minimum_required(VERSION 3.14)
project(chap02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(chap02
        ac.h
        seqlist.cpp)
