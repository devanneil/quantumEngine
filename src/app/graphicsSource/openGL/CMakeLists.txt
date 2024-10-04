cmake_minimum_required(VERSION 3.30.0)

# Fetch GLFW
find_package(glfw3 QUIET)

if (NOT glfw3_FOUND)
    message(STATUS "GLFW not found, using FetchContent to install it.")
    include(FetchContent)
    FetchContent_Declare(
        glfw3
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
    )
    FetchContent_MakeAvailable(glfw3)
else()
    message(STATUS "Found GLFW on the system.")
endif()

# Find OpenGL
find_package(OpenGL REQUIRED)

add_library(qOpenGL STATIC qOpenGL.cpp)

target_include_directories(qOpenGL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(qOpenGL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include)

# Link the libraries to your executable
target_link_libraries(qOpenGL 
    glfw
    OpenGL::GL
    qVec
    qMat
    qLinMat
)