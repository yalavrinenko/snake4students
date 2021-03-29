cmake_minimum_required(VERSION 3.17.5)
project(snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror -fanalyzer")

add_executable(snake main.cpp snake.cpp game_field.cpp game_field.hpp player.cpp player.hpp)