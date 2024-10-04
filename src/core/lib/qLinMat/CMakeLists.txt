# Create the qLinMat INTERFACE library
add_library(qLinMat INTERFACE)

# Link qLinMat with qVec and qMat (since qLinMat depends on both)
target_link_libraries(qLinMat INTERFACE qVec qMat)

# Specify the include directory for qLinMat (so other targets can use qLinMat)
target_include_directories(qLinMat INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Specify the include directory for qMat (so qLinMat can use qMat)
target_include_directories(qMat PUBLIC ${PROJECT_SOURCE_DIR}/core/lib/qMat)

# Specify the include directory for qVec (so qLinMat can use it)
target_include_directories(qVec PUBLIC ${PROJECT_SOURCE_DIR}/core/lib/qVec)
