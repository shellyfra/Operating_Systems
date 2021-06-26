cmake_minimum_required(VERSION 3.0.0)
project(MMU VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(MMU_1 tests/test1.cpp)
add_executable(MMU_2 tests/test2.cpp)
add_executable(MMU_3 tests/test3.cpp)
add_executable(MMU_5 tests/test5.cpp)
add_executable(MMU_6 tests/test6.cpp)
add_executable(MMU_7 tests/test7.cpp)
add_executable(MMU_14 tests/test14.cpp)

add_executable(MMU_247 tests/test247.cpp)
add_executable(tamuz adjusted_tests_hw4/tamuz_modified_tests_for_malloc_2.cpp)
add_executable(tamuz_tests_hw4_malloc4 adjusted_tests_hw4/tamuz_tests_hw4_malloc4.cpp)
add_executable(malloc2_test01 adjusted_tests_hw4/malloc2_test01.cpp)
add_executable(malloc3_test01 adjusted_tests_hw4/malloc3_test01.cpp)
add_executable(malloc3_test02 adjusted_tests_hw4/malloc3_test02.cpp)
add_executable(malloc4_test01 adjusted_tests_hw4/malloc4_test01.cpp)
add_executable(malloc_3_tests adjusted_tests_hw4/malloc_3_tests.cpp)
add_executable(malloc_3_tests_realloc adjusted_tests_hw4/malloc_3_tests_realloc.cpp)
add_executable(mainTest2 adjusted_tests_hw4/mainTest2.cpp)
add_executable(mainTest3 adjusted_tests_hw4/mainTest3.cpp)
add_executable(mainTest4 adjusted_tests_hw4/mainTest4.cpp)
add_executable(test_whatsup adjusted_tests_hw4/test_whatsup.cpp)
add_executable(test_realloc_2 adjusted_tests_hw4/test_realloc_2.cpp)
add_executable(test_realloc_3 adjusted_tests_hw4/test_realloc_3.cpp)
add_executable(tamuz_tests_hw4_malloc2 adjusted_tests_hw4/tamuz_tests_hw4_malloc2.cpp)
#add_executable(MMU_3 tests/test3.cpp)
#add_executable(MMU_4 tests/test4.cpp)
add_compile_options(-Wall -Wextra -pedantic -Werror -pedantic-errors)

list(APPEND debug_flags "-std=c++11"  "-pedantic" "-Werror" "-pedantic-errors" "-DDEBUG")
target_compile_options(mainTest3
  PRIVATE
    ${debug_flags}
  )
  target_compile_options(tamuz_tests_hw4_malloc4
  PRIVATE
    ${debug_flags}
  )
  target_compile_options(malloc_3_tests
  PRIVATE
    ${debug_flags}
  )
  target_compile_options(MMU_6
  PRIVATE
    ${debug_flags}
  )
  target_compile_options(MMU_7
  PRIVATE
    ${debug_flags}
  )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
