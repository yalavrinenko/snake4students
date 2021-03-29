cmake_minimum_required(VERSION 3.17.5)
project(snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

add_executable(snake main.cpp)