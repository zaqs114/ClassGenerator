cmake_minimum_required(VERSION 3.6)
project(ClassGenerator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp kappa.cpp kappa.h)
add_executable(ClassGenerator ${SOURCE_FILES})