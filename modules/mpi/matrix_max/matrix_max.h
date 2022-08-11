// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_MATRIX_MAX_MATRIX_MAX_H_
#define MODULES_MPI_MATRIX_MAX_MATRIX_MAX_H_

int* getRandomMatrix(int n, int m);
int getSequentialMax(int* matrix, int n, int m);
int getParallelMax(int* matrix, int n, int m);

#endif  // MODULES_MPI_MATRIX_MAX_MATRIX_MAX_H_
