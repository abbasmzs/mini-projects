#include <iostream>
#include "shared_memory.h"

void fixBrokenCells(SharedMatrix& sharedMatrix) {
    Matrix* matrix = sharedMatrix.getMatrix();

    for (int row = 0; row < matrix->getRows(); ++row) {
        for (int col = 0; col < matrix->getCols(); ++col) {
            if (matrix->isBroken(row, col)) {
                matrix->fixCell(row, col);
                std::cout << "Fixed cell at (" << row << ", " << col << ")\n";
            }
        }
    }
}

int main() {
    const char* shm_name = "/matrix_shm";
    size_t matrix_size = sizeof(Matrix);

    SharedMatrix sharedMatrix(shm_name, matrix_size);
    fixBrokenCells(sharedMatrix);
    sharedMatrix.detach();

    return 0;
}