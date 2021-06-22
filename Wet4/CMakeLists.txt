cmake_minimum_required(VERSION 3.0.0)
project(MMU VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(MMU_1 tests/test1.cpp)
add_executable(MMU_2 tests/test2.cpp)
#add_executable(MMU_3 tests/test3.cpp)
#add_executable(MMU_4 tests/test4.cpp)
add_compile_options(-Wall -Wextra -pedantic -Werror -pedantic-errors)

list(APPEND debug_flags "-std=c++11" "-Wall" "-Wextra" "-pedantic" "-Werror" "-pedantic-errors" "-DDEBUG")
target_compile_options(MMU_1
  PRIVATE
    ${debug_flags}
  )
  target_compile_options(MMU_2
  PRIVATE
    ${debug_flags}
  )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
