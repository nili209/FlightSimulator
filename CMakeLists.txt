cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(ex3 main.cpp Singleton.cpp)