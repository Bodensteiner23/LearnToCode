cmake_minimum_required(VERSION 3.29)
project(Bank_Account_System C)

set(CMAKE_C_STANDARD 11)

# Remove -Werror to prevent warnings from being treated as errors
string(REPLACE "-Werror" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

add_executable(Bank_Account_System main.c)
