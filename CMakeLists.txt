cmake_minimum_required(VERSION 3.16)

project(CNodes C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(CNodes ${SOURCES})

target_include_directories(CNodes PRIVATE include)
