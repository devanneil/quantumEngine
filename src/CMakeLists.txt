cmake_minimum_required(VERSION 3.30.0)
project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
# Disable all optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

add_executable(main main.cpp)

add_subdirectory(core/lib/qVec)
add_subdirectory(core/lib/qMat)

target_link_libraries(main qVec)
target_link_libraries(main qMat)