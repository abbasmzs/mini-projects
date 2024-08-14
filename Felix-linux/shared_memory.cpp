#include "shared_memory.h"
#include <iostream>

SharedMatrix::SharedMatrix(const char* name, size_t size) {
#ifdef _WIN32
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    // default security
        PAGE_READWRITE,          // read/write access
        0,                       // maximum object size (high-order DWORD)
        size,                    // maximum object size (low-order DWORD)
        name);                   // name of mapping object

    if (hMapFile == NULL) {
        std::cerr << "Could not create file mapping object: " << GetLastError() << std::endl;
        exit(1);
    }

    matrix = static_cast<Matrix*>(MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, size));

    if (matrix == NULL) {
        std::cerr << "Could not map view of file: " << GetLastError() << std::endl;
        CloseHandle(hMapFile);
        exit(1);
    }

#else
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd < 0) {
        perror("shm_open");
        exit(1);
    }

    if (ftruncate(shm_fd, size) == -1) {
        perror("ftruncate");
        exit(1);
    }

    matrix = static_cast<Matrix*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (matrix == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
#endif
}

SharedMatrix::~SharedMatrix() {
#ifdef _WIN32
    if (matrix) {
        UnmapViewOfFile(matrix);
    }
    CloseHandle(hMapFile);
#else
    if (matrix) {
        munmap(matrix, sizeof(Matrix));
    }
    close(shm_fd);
#endif
}

Matrix* SharedMatrix::getMatrix() {
    return matrix;
}

void SharedMatrix::detach() {
#ifdef _WIN32
    if (matrix) {
        UnmapViewOfFile(matrix);
        matrix = nullptr;
    }
#else
    if (matrix) {
        munmap(matrix, sizeof(Matrix));
        matrix = nullptr;
    }
#endif
}