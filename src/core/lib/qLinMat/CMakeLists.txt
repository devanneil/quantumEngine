add_library(qVec STATIC qVec.cpp)

target_include_directories(qVec 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})
   
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
