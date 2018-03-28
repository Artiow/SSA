cmake_minimum_required(VERSION 3.9)
project(SSA)

set(CMAKE_CXX_STANDARD 17)

#TEST_GENERATORS
set(TEST_GENERATORS libs/generators.h)
add_library(GLOBAL_LIBS ${TEST_GENERATORS})

#LAB 1 LIBS
set(GLUE Lab1/logic/glue.h)
set(BORDER_SEARCH Lab1/logic/bordersearch.h)
set(BLOCK_SEARCH Lab1/logic/blocksearch.h)
add_library(Lab1_LIBS ${GLUE} ${BORDER_SEARCH} ${BLOCK_SEARCH})
#LAB 1 TEST
set(Lab1_TESTFILE Lab1/testing/test.h)
add_library(Lab1_TESTBLOCK ${Lab1_TESTFILE})
#LAB 1 EXECUTABLE
add_executable(Lab1_TEST Lab1/main.cpp)

#LAB 2 LIBS
set(MBA_BUILDER Lab2/logic/mbabuilder.h)
set(KMP_SEARCH Lab2/logic/kmpsearch.h)
add_library(Lab2_LIBS ${MBA_BUILDER} ${KMP_SEARCH})
#LAB 2 TEST
set(Lab2_TESTFILE Lab2/testing/test.h)
add_library(Lab2_TESTBLOCK ${Lab2_TESTFILE})
#LAB 2 EXECUTABLE
add_executable(Lab2_TEST Lab2/main.cpp)

#LAB 3 LIBS
set(BASIC Lab3/logic/basic.h)
set(BM_SEARCH Lab3/logic/bmsearch.h)
add_library(Lab3_LIBS ${MBA_BUILDER} ${KMP_SEARCH})
#LAB 2 TEST
set(Lab3_TESTFILE Lab3/testing/test.h)
add_library(Lab3_TESTBLOCK ${Lab3_TESTFILE})
#LAB 3 EXECUTABLE
add_executable(Lab3_TEST Lab3/main.cpp)