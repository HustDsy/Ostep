cmake_minimum_required(VERSION 3.16)
project(Ostep)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Chapter-5)

add_executable(test ./Chapter-5/test.c)
add_executable(5.1 ./Chapter-5/5.1.c)
add_executable(5.2 ./Chapter-5/5.2.c)
add_executable(5.3 ./Chapter-5/5.3.c)
add_executable(5.4 ./Chapter-5/5.4.c)
add_executable(5.5 ./Chapter-5/5.5.c)
add_executable(5.6 ./Chapter-5/5.6.c)
add_executable(5.7 ./Chapter-5/5.7.c)
add_executable(5.8 ./Chapter-5/5.8.c)
add_executable(1111 ./Chapter-5/1111.cpp)