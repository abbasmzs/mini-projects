#include "MatrixFixer.h"
#include <iostream>

int main(int argc, char** argv) {
    int rows = 700;
    int cols = 700;
    int num_problems = 1000;

    // Parse command line arguments if provided
    if (argc > 1) rows = std::stoi(argv[1]);
    if (argc > 2) cols = std::stoi(argv[2]);
    if (argc > 3) num_problems = std::stoi(argv[3]);

    // Create a MatrixFixer object and run the process
    MatrixFixer fixer(rows, cols, num_problems);
    fixer.run();

    return 0;
}