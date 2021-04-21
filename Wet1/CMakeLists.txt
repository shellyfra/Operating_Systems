cmake_minimum_required(VERSION 3.10)
project(Operation_Systems)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11 -Wall )
add_executable(Operation_Systems Commands.cpp Commands.h signals.h signals.cpp smash.cpp)

