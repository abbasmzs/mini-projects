Software Motion Challenge
========
we have here 3 mini projects as a c++ challenge.

1- Elden Tree
------------- 
src/: Directory for source code files (.cpp).
. EldenTree.cpp: Core implementation of the event handler.
. EventQueue.cpp: Implementation of a concurrent event queue.
. Event.cpp: Implementation of the event data structure.

include/: Directory for header files (.h).
. EldenTree.h: Header file for the EldenTree class.
. EventQueue.h: Header file for the EventQueue class.
. Event.h: Header file for the Event class.

tests/: Directory for test files.
. test_event_handler.cpp: Unit tests for the event handler using Google Test.

•	Each event added to the Elden Tree will be processed and printed to the console.
•	The output will include the god's name, the event data, and a timestamp.

Summary:
1.	Install vcpkg: Clone and bootstrap vcpkg, then integrate it with Visual Studio.
2.	Install Google Test: Use vcpkg to install Google Test with .\vcpkg install gtest.
3.	Set Up Project: Add Google Test to project by configuring include and library directories if necessary.
4.	Run Tests: Build and run your tests using Visual Studio.


2- FELIX
-------------
src/:
. MatrixFixer.cpp
. main.cpp

include/:
. MatrixFixer.h

tests/:
. MatrixFixerTests.cpp

CMake build configuration/:
. CMakeLists.txt

Summary:
1. Matrix creation with specified dimensions and initial values.
2. Introduction of random problems in the matrix.
3. Multithreaded fixing of problems.
4. Command-line configurable parameters.


## Setup Instructions
### Prerequisites

- [OpenCV](https://opencv.org/releases/) installed and configured on your system. (Just for Felix)
- CMake 3.10 or higher.
- A C++ compiler (e.g., GCC, Clang, or Visual Studio).

### Build Instructions

1. Clone the repository:

    ```bash
    git clone <https://github.com/abbasmzs/mini-projects>
    cd MatrixFixerProject
    ```

2. Create a build directory and run CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    ```

3. Build the project:

    ```bash
    cmake --build .
    ```

4. Run the executable:

    ```bash
    ./MatrixFixerProject 700 700 1000
    ```
