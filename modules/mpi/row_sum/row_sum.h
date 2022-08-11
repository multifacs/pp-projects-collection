// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_ROW_SUM_ROW_SUM_H_
#define MODULES_MPI_ROW_SUM_ROW_SUM_H_

int* getRandomMatrix(int rows, int cols);
int* getParallelOperations(int* matrix, int rows, int cols);
int* getSequentialOperations(int* matrix, int rows, int cols);

#endif  // MODULES_MPI_ROW_SUM_ROW_SUM_H_
