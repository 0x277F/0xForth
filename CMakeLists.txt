cmake_minimum_required(VERSION 3.3)
project(0xForth)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

file(GLOB SOURCE_FILES *.c)
add_library(0xForth ${SOURCE_FILES})