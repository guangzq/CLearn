cmake_minimum_required(VERSION 3.16)
project(mat)

set(CMAKE_C_STANDARD 11)

add_executable(mat main.cpp)
add_executable(Matrix matrix.c)
add_executable(SizeOne  SizeOne.c)
add_executable(ReversalStr ReversalStr.c)
add_executable(MethodPointer MethodPointer.c)
add_executable(elf elf.c)
add_executable(StringU StringU.c)
add_executable(FileTest FileTest.c)