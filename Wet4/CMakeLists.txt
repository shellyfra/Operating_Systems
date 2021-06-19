cmake_minimum_required(VERSION 3.0.0)
project(MMU VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MMU tests/main1.cpp)
add_executable(MMU_1 tests/main1.cpp tests/sbrk_faulty.cpp)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -Werror -pedantic-errors")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
