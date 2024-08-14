#ifdef _WIN32
#include <windows.h>
#else
#include <sys/wait.h>
#endif

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include "shared_memory.h"
#include "matrix.h"

int main(int argc, char* argv[]) {
    int rows = 5;
    int cols = 5;
    int numFelixes = 3;

    // Create and initialize the matrix in shared memory
    SharedMatrix sharedMatrix("/matrix_shm", sizeof(Matrix));
    Matrix* matrix = sharedMatrix.getMatrix();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                matrix->setBroken(i, j);
            }
        }
    }

    // Spawn Felix processes
    for (int i = 0; i < numFelixes; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execlp("./felix", "felix", nullptr);
            perror("execlp failed");
            exit(1);
        }
        else if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
    }

    // Wait for all Felix processes to complete
    while (wait(nullptr) > 0);

    // Clean up
    shm_unlink("/matrix_shm");
    std::cout << "All Felix processes have finished.\n";

    return 0;
}