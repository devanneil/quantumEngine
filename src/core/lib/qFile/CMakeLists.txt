add_library(qFile STATIC qFile.cpp)

target_include_directories(qFile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#CMAKE Tests configuration
set(CURRENT_TEST "qFile")
include(cTest)
add_executable(${CURRENT_TEST}Test unitTests.cpp)
target_link_libraries(${CURRENT_TEST}Test 
    #INCLUDE LIBRARY TO TEST HERE
    qFile
)
add_test(NAME Q_FILE_TEST COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${CURRENT_TEST}Test)

##NOTE: to make changes to test we need to clean rebuild. Either remove /build directory or run clean rebuild in vs code