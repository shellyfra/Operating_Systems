cmake_minimum_required(VERSION 3.0.0)
project(WebServer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(WebServer server.c request.c segel.c queue.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -Werror -pedantic-errors -Wall")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)