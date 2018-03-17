cmake_minimum_required(VERSION 3.9)
project(SSA)

set(CMAKE_CXX_STANDARD 17)

#SAMPLES
set(SAMPLE_1 samples/sample1.txt)
set(SAMPLE_2 samples/sample2.txt)
add_library(SAMPLES ${SAMPLE_1} ${SAMPLE_2})

#GLOBAL LIBS
set(FILE_READER libs/filereader.h)
set(DNA_GENERATOR libs/dnagenerator.h)
set(TEST_GENERATOR libs/testgenerator.h)
add_library(GLOBAL_LIBS ${FILE_READER} ${DNA_GENERATOR} ${TEST_GENERATOR})

#LAB 1 LIBS
set(GLUE Lab1/logic/glue.h Lab1/test/test.h)
set(BORDER_SEARCH Lab1/logic/bordersearch.h)
set(BLOCK_SEARCH Lab1/logic/blocksearch.h)
add_library(Lab1_LIBS ${GLUE} ${BORDER_SEARCH} ${BLOCK_SEARCH})
#LAB 1 EXECUTABLE
set(Lab1_TESTBLOCK Lab1/test/test.h)
add_executable(Lab1_DNA Lab1/dnasearch.cpp)
add_executable(Lab1_FILE Lab1/filesearch.cpp)
add_executable(Lab1_TEST Lab1/testsearch.cpp ${Lab1_TESTBLOCK})

#LAB 2 LIBS
set(MBA_BUILDER Lab2/logic/mbabuilder.h)
set(KMP_SEARCH Lab2/logic/kmpsearch.h)
add_library(Lab2_LIBS ${MBA_BUILDER} ${KMP_SEARCH} Lab2/test/test.h)
#LAB 2 EXECUTABLE
set(Lab2_TESTBLOCK Lab2/test/test.h)
add_executable(Lab2_DNA Lab2/dnasearch.cpp)
add_executable(Lab2_FILE Lab2/filesearch.cpp)
add_executable(Lab2_TEST Lab2/testsearch.cpp ${Lab2_TESTBLOCK})