cmake_minimum_required(VERSION 2.8.9)
project (cpp_sucks)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ")

file(GLOB_RECURSE SOURCES "src/**.cpp")

add_executable(cpp_sucks ${SOURCES})
