#ifndef MATRIXFIXER_H
#define MATRIXFIXER_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <thread>
#include <mutex>

class MatrixFixer {
private:
    cv::Mat matrix;
    int rows, cols;
    int num_problems;
    std::mutex mtx;

    void introduceProblems();
    void searchAndFixProblems();
    void fixProblem(int row, int col);

public:
    MatrixFixer(int rows, int cols, int num_problems);
    void run();
};

#endif // MATRIXFIXER_H