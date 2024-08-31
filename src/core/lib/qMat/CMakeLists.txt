add_library(qMat STATIC qMat.cpp)

add_subdirectory(../qVec)

target_link_libraries(qMat qVec)

target_include_directories(qMat 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})