# Create the qMat static library
add_library(qMat STATIC qMat.cpp)

# Link qMat with qVec (since qMat depends on qVec)
target_link_libraries(qMat PUBLIC qVec)

# Specify the include directory for qMat (so other targets can use qMat)
target_include_directories(qMat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Specify the include directory for qVec (so qMat can use it)
target_include_directories(qMat PUBLIC ${PROJECT_SOURCE_DIR}/core/lib/qVec)
