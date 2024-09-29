cmake_minimum_required(VERSION 3.29)
project(Bank_Account_System C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Remove -Werror to prevent warnings from being treated as errors
string(REPLACE "-Werror" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/Inc)

add_executable(Bank_Account_System 
                main.c
                # Inc/Console.h     If more Files needs to be included just add them all here
                )
