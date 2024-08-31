cmake_minimum_required(VERSION 3.30.2)
project(qVecTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(qVecTest main.cpp)

add_subdirectory(core/lib/qVec)

target_link_libraries(qVecTest qVec)