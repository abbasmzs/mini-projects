//#include <gtest/gtest.h>
//#include "shared_memory.h"
//#include <unistd.h> // for getpid
//
//TEST(SharedMatrixTest, SharedMemory) {
//    const char* shm_name = "/matrix_shm";
//    size_t matrix_size = sizeof(Matrix);
//    SharedMatrix sharedMatrix(shm_name, matrix_size);
//
//    Matrix* matrix = sharedMatrix.getMatrix();
//    matrix->setBroken(0, 0);
//    EXPECT_TRUE(matrix->isBroken(0, 0));
//    matrix->fixCell(0, 0);
//    EXPECT_FALSE(matrix->isBroken(0, 0));
//
//    sharedMatrix.detach();
//}