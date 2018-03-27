cmake_minimum_required(VERSION 3.9)
project(SSA)

set(CMAKE_CXX_STANDARD 17)

#SAMPLES
set(SAMPLE_1 samples/sample1.txt)
set(SAMPLE_2 samples/sample2.txt)
add_library(SAMPLES ${SAMPLE_1} ${SAMPLE_2})

#GLOBAL LIBS
set(FILE_READER libs/filereader.h)
set(TEST_GENERATOR libs/testgenerator.h)
set(DNA_GENERATOR libs/dnagenerator.h)
add_library(GLOBAL_LIBS ${FILE_READER} ${TEST_GENERATOR} ${DNA_GENERATOR})

#LAB 1 LIBS
set(GLUE Lab1/logic/glue.h Lab1/test/test.h)
set(BORDER_SEARCH Lab1/logic/bordersearch.h)
set(BLOCK_SEARCH Lab1/logic/blocksearch.h)
add_library(Lab1_LIBS ${GLUE} ${BORDER_SEARCH} ${BLOCK_SEARCH})
#LAB 1 TEST
set(Lab1_TESTFILE Lab1/test/test.h)
add_library(Lab1_TESTBLOCK ${Lab1_TESTFILE})
#LAB 1 EXECUTABLE
#add_executable(Lab1_FILE Lab1/filesearch.cpp)
add_executable(Lab1_TEST Lab1/testsearch.cpp)

#LAB 2 LIBS
set(MBA_BUILDER Lab2/logic/mbabuilder.h)
set(KMP_SEARCH Lab2/logic/kmpsearch.h)
add_library(Lab2_LIBS ${MBA_BUILDER} ${KMP_SEARCH} Lab2/test/test.h)
#LAB 2 TEST
set(Lab2_TESTFILE Lab2/test/test.h)
add_library(Lab2_TESTBLOCK ${Lab2_TESTFILE})
#LAB 2 EXECUTABLE
#add_executable(Lab2_FILE Lab2/filesearch.cpp)
add_executable(Lab2_TEST Lab2/testsearch.cpp)