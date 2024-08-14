#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

#include <stddef.h>
#include "matrix.h"

class SharedMatrix {
public:
    SharedMatrix(const char* name, size_t size);
    ~SharedMatrix();

    Matrix* getMatrix();
    void detach();

private:
#ifdef _WIN32
    HANDLE hMapFile;
#else
    int shm_fd;
#endif
    Matrix* matrix;
};

#endif // SHARED_MEMORY_H