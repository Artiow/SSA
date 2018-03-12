cmake_minimum_required(VERSION 3.9)
project(SSA)

set(CMAKE_CXX_STANDARD 17)

set(SAMPLE_1 samples/sample1.txt)
set(SAMPLE_2 samples/sample2.txt)
add_library(samples ${SAMPLE_1} ${SAMPLE_2})

set(FILE_READER libs/filereader.h)
set(DNA_GENERATOR libs/dnagenerator.h)
add_library(libs ${FILE_READER} ${DNA_GENERATOR})

add_executable(Lab1_DNA Lab1/dnasearch.cpp Lab1/modules/glue.h Lab1/modules/bordersearch.h Lab1/modules/blocksearch.h)
add_executable(Lab1_FILE Lab1/filesearch.cpp Lab1/modules/glue.h Lab1/modules/bordersearch.h Lab1/modules/blocksearch.h)