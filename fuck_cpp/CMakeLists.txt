cmake_minimum_required(VERSION 2.8.9)
project (fuck_cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(fuck_cpp ${SOURCES})
