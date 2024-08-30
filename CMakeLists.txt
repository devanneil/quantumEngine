# CMakeLists.txt for the sorting project
cmake_minimum_required(VERSION 3.14)

# Ensure we can use gdb
set(CMAKE_BUILD_TYPE Debug)

project(project5-bfs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_compile_options(-pedantic -Wall -Wextra)

add_executable(run-main src/main.cpp)
