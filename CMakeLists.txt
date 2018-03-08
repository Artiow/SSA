cmake_minimum_required(VERSION 3.9)
project(SSA)

set(CMAKE_CXX_STANDARD 17)

set(SAMPLE_0 samples/sample0.txt samples/pattern0.txt)
add_library(samples ${SAMPLE_0})

add_executable(Lab1 Lab1/main.cpp Lab1/modules/glue.h Lab1/modules/bordersearch.h Lab1/modules/blocksearch.h)