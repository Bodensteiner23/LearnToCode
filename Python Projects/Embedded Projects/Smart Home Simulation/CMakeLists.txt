# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SmartHomeSimulation VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Remove -Werror to prevent warnings from being treated as errors
string(REPLACE "-Werror" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

# Add executable target with updated paths
add_executable(smart_home 
                logic/Src/main.c 
                logic/Src/sensor.c 
                logic/Src/app.c)

# Include directories
target_include_directories(smart_home PRIVATE ${PROJECT_SOURCE_DIR}/logic/Inc)
