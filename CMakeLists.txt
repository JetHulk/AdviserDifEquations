cmake_minimum_required(VERSION 3.13)
project(Adviser)

set(CMAKE_CXX_STANDARD 14)

add_executable(Adviser main.cpp Node.cpp Node.h newNode.h Functions.cpp)