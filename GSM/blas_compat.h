// BLAS/LAPACK compatibility header for cross-platform support
// Abstracts differences between MKL (Linux) and OpenBLAS (macOS)

#ifndef BLAS_COMPAT_H
#define BLAS_COMPAT_H

#ifdef __APPLE__
// macOS with OpenBLAS/Accelerate
#include <cblas.h>

// Define MKL_INT as int for compatibility with existing code
typedef int MKL_INT;

// Declare LAPACK functions (Fortran interface)
extern "C" {
    void dgesvd_(char*, char*, int*, int*, double*, int*, double*, double*, int*,
                 double*, int*, double*, int*, int*);
    void dgetrf_(int*, int*, double*, int*, int*, int*);
    void dgetri_(int*, double*, int*, int*, double*, int*, int*);
    void dsyevx_(char*, char*, char*, int*, double*, int*, double*, double*,
                 int*, int*, double*, int*, double*, double*, int*, double*,
                 int*, int*, int*, int*);
    void dsyevd_(char*, char*, int*, double*, int*, double*, double*, int*,
                 int*, int*, int*);
}

#else
// Linux with MKL
#include <mkl.h>
#endif

#endif // BLAS_COMPAT_H
