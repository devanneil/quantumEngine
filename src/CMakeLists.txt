cmake_minimum_required(VERSION 3.30.0)
project(QuantumEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for your core libraries
add_subdirectory(core/lib/qLinMat)
add_subdirectory(core/lib/qMesh)
add_subdirectory(core/lib/qFile)
# Add subdirectory for the main application
add_subdirectory(app)