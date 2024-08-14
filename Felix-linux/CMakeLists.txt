cmake_minimum_required(VERSION 3.10)
project(Felix)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add executable
add_executable(felix_project
    src/main.cpp
    src/matrix.cpp
    src/shared_memory.cpp
    src/felix.cpp
)

# Include directories
include_directories(include)

# Add test executable
enable_testing()
add_executable(test_felix
    tests/test_matrix.cpp
    tests/test_shared_memory.cpp
)

# Link Google Test library
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(test_felix ${GTEST_LIBRARIES} pthread)

# Add test directory
add_test(NAME MatrixTest COMMAND test_felix)
