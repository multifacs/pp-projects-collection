// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_MATRIX_SUM_MATRIX_SUM_H_
#define MODULES_MPI_MATRIX_SUM_MATRIX_SUM_H_

int* getRandomMatrix(int size);
int getSequentialSum(int* matrix, int size);
int getParallelSum(int* matrix, int msize);

#endif  // MODULES_MPI_MATRIX_SUM_MATRIX_SUM_H_
