#include "MatrixFixer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

MatrixFixer::MatrixFixer(int rows, int cols, int num_problems)
    : rows(rows), cols(cols), num_problems(num_problems) {
    matrix = cv::Mat(rows, cols, CV_32S, cv::Scalar(100));
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void MatrixFixer::introduceProblems() {
    std::cout << "Introducing random problems..." << std::endl;
    for (int i = 0; i < num_problems; i++) {
        int row = std::rand() % rows;
        int col = std::rand() % cols;
        matrix.at<int>(row, col) = 0; // Set some random pixels to 0
    }
}

void MatrixFixer::fixProblem(int row, int col) {
    std::lock_guard<std::mutex> lock(mtx); // Lock the matrix for thread safety
    if (matrix.at<int>(row, col) != 100) {
        matrix.at<int>(row, col) = 100;
        std::cout << "Fixed problem at (" << row << ", " << col << ") by thread " << std::this_thread::get_id() << std::endl;
    }
}

void MatrixFixer::searchAndFixProblems() {
    std::vector<std::thread> threads;
    std::cout << "Searching for and fixing problems..." << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix.at<int>(i, j) != 100) {
                // Create a thread to fix the problem
                threads.push_back(std::thread(&MatrixFixer::fixProblem, this, i, j));
            }
        }
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void MatrixFixer::run() {
    introduceProblems();
    searchAndFixProblems();
}