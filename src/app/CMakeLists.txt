cmake_minimum_required(VERSION 3.30.0)
project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(main 
    main.cpp     
    glad.c
    )

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/graphicsSource/openGL)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Link the necessary libraries to the main executable
target_link_libraries(main 
    qVec     # Your custom vector library
    qMat     # Your custom matrix library
    qLinMat
    qOpenGL  # The OpenGL-related library
    qMesh
    qFile
)