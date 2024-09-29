cmake_minimum_required(VERSION 3.30.0)
project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(main main.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/graphicsSource/openGL)

# Link the necessary libraries to the main executable
target_link_libraries(main 
    qOpenGL  # The OpenGL-related library
    qVec     # Your custom vector library
    qMat     # Your custom matrix library
)