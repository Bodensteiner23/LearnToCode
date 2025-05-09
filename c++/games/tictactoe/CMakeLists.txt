cmake_minimum_required(VERSION 3.30)
project(tictactoe)

set(CMAKE_CXX_STANDARD 20)

add_executable(tictactoe main.cpp)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)
target_link_libraries(tictactoe PRIVATE SFML::Graphics SFML::Audio SFML::Network)


