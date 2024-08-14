#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols);
    void setBroken(int row, int col);
    bool isBroken(int row, int col) const;
    void fixCell(int row, int col);
    void print() const;

    int getRows() const;
    int getCols() const;

private:
    std::vector<std::vector<int>> data;
};

#endif // MATRIX_H