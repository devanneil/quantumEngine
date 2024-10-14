# Create the qMesh INTERFACE library
add_library(qMesh STATIC qMesh.cpp)

# Link qMesh with qVec and qMat (since qMesh depends on both)
target_link_libraries(qMesh PUBLIC qVec qMat)

# Specify the include directory for qMesh (so other targets can use qMesh)
target_include_directories(qMesh PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Specify the include directory for qMat (so qMesh can use qMat)
target_include_directories(qMat PUBLIC ${PROJECT_SOURCE_DIR}/core/lib/qMat)

# Specify the include directory for qVec (so qMesh can use it)
target_include_directories(qVec PUBLIC ${PROJECT_SOURCE_DIR}/core/lib/qVec)