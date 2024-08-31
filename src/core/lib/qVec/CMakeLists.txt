add_library(qVec STATIC qVec.cpp)

target_include_directories(qVec 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})