#include "matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols) : data(rows, std::vector<int>(cols, 1)) {}

void Matrix::setBroken(int row, int col) {
    data[row][col] = 0;
}

bool Matrix::isBroken(int row, int col) const {
    return data[row][col] == 0;
}

void Matrix::fixCell(int row, int col) {
    data[row][col] = 1;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::getRows() const { return static_cast<int>(data.size()); }
int Matrix::getCols() const { return static_cast<int>(data[0].size()); }