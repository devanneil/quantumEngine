add_library(qVec STATIC qVec.cpp)

target_include_directories(qVec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
   
# Create the qMat static library
add_library(qMat STATIC qMat.cpp)

# Link qMat with qVec (since qMat depends on qVec)
target_link_libraries(qMat PUBLIC qVec)

# Create the qLinMat INTERFACE library
add_library(qLinMat INTERFACE)

# Link qLinMat with qVec and qMat (since qLinMat depends on both)
target_link_libraries(qLinMat INTERFACE qVec qMat)

# Specify the include directory for qLinMat (so other targets can use qLinMat)
target_include_directories(qLinMat INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

#CMAKE Tests configuration
set(CURRENT_TEST "qLinMat")
include(cTest)
add_executable(${CURRENT_TEST}Test unitTests.cpp)
target_link_libraries(${CURRENT_TEST}Test 
    #INCLUDE LIBRARY TO TEST HERE
    qVec
    qMat
    qLinMat
)
add_test(NAME Q_LINEAR_MATH_TEST COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${CURRENT_TEST}Test)

##NOTE: to make changes to test we need to clean rebuild. Either remove /build directory or run clean rebuild in vs code