cmake_minimum_required(VERSION 3.16)
project(mat)

set(CMAKE_C_STANDARD 11)

add_executable(mat main.cpp)
add_executable(Matrix matrix.c)