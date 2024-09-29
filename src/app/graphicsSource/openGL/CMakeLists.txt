cmake_minimum_required(VERSION 3.30.0)
# Fetch GLFW
find_package(GLFW QUIET)

if (NOT GLFW_FOUND)
    message(STATUS "GLFW not found, using FetchContent to install it.")
    include(FetchContent)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
    )
    FetchContent_MakeAvailable(glfw)
else()
    message(STATUS "Found GLFW on the system.")
endif()

# Fetch GLEW
find_package(GLEW QUIET)

if (NOT GLEW_FOUND)
    message(STATUS "GLEW not found, using FetchContent to install it.")
    include(FetchContent)
    FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/nigels-com/glew.git
        GIT_TAG glew-2.2.0
    )
    FetchContent_MakeAvailable(glew)
else()
    message(STATUS "Found GLEW on the system.")
endif()

# Find OpenGL
find_package(OpenGL REQUIRED)

add_library(qOpenGL SHARED qOpenGL.cpp)
# Link the libraries to your executable
target_link_libraries(qOpenGL 
    glfw 
    GLEW::GLEW 
    OpenGL::GL
    qVec
    qMat
)

target_include_directories(qOpenGL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})