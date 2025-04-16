cmake_minimum_required(VERSION 3.30)
project(2_anlage)

set(CMAKE_CXX_STANDARD 20)

add_executable(2_anlage main.cpp
        Sensor.h
        DI_0_24V_Input.h)
