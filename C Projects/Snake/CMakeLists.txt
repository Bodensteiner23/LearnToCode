cmake_minimum_required(VERSION 3.29)
project(Snake C)

set(CMAKE_C_STANDARD 11)

add_executable(Snake main.c)

target_link_libraries(Snake ncurses)