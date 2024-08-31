add_library(qMat STATIC qMat.cpp)

include_directories(${PROJECT_SOURCE_DIR}/core/lib/qVec)

target_link_libraries(qMat qVec)

target_include_directories(qMat 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})