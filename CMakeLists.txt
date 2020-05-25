cmake_minimum_required(VERSION 3.16)
project(nlp_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(nlp_cpp main.cpp ch02/Utils.h ch02/Utils.cpp ch02/segment.h ch02/segment.cpp)