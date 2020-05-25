cmake_minimum_required(VERSION 3.16)
project(nlp_cpp)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory("ch02" CH02)
add_executable(nlp_cpp main.cpp ${CH02})