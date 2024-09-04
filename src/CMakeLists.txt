cmake_minimum_required(VERSION 3.30.0)
project(qVecTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(qVecTest main.cpp)

add_subdirectory(core/lib/qVec)
add_subdirectory(core/lib/qMat)

target_link_libraries(qVecTest qVec)
target_link_libraries(qVecTest qMat)