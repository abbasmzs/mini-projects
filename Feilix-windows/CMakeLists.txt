cmake_minimum_required(VERSION 3.10)

# Project name
project(MatrixFixerProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS} include)

# Source files
set(SOURCES src/main.cpp src/MatrixFixer.cpp)

# Add executable
add_executable(MatrixFixerProject ${SOURCES})

# Link OpenCV libraries
target_link_libraries(MatrixFixerProject ${OpenCV_LIBS})

# Set up testing (optional)
enable_testing()
add_subdirectory(tests)
