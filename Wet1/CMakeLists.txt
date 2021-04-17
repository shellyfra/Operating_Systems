cmake_minimum_required(VERSION 3.10)
project(Operating_Systems)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11 -Wall )
add_executable(Operating_Systems Commands.cpp Commands.h signals.h signals.cpp smash.cpp)

