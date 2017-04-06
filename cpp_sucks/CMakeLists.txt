cmake_minimum_required(VERSION 2.8.9)
project (cpp_sucks)

file(GLOB SOURCES "src/*.cpp")

add_executable(cpp_sucks ${SOURCES})
