
cmake_minimum_required(VERSION 3.17)
project(Workspace C)

set(CMAKE_C_STANDARD 11)

add_executable(Workspace main.c fromBMP.c bmp.c util.c toBMP.c rotatedMethod.c open_close_file.c)