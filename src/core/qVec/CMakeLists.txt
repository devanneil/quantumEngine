cmake_minimum_required(VERSION 3.30.2)
project(qVecTest)

add_executable(qVecTest main.cpp)

add_subdirectory(lib)

target_link_libraries(qVecTest qVec)