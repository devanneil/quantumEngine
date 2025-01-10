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

#CMAKE Tests configuration
set(CURRENT_TEST "qMesh")
include(cTest)
add_executable(${CURRENT_TEST}Test unitTests.cpp)
target_link_libraries(${CURRENT_TEST}Test 
    #INCLUDE LIBRARY TO TEST HERE
    qMesh
)
add_test(NAME Q_FILE_TEST COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${CURRENT_TEST}Test)

##NOTE: to make changes to test we need to clean rebuild. Either remove /build directory or run clean rebuild in vs code