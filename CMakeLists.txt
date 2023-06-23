cmake_minimum_required(VERSION 3.23)
project(myos C)

set(CMAKE_C_STANDARD 99)

add_executable(myos main.c tools/floppy.c tools/fileinfo.c)
