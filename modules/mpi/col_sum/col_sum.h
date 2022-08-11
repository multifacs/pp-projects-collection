// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_COL_SUM_COL_SUM_H_
#define MODULES_MPI_COL_SUM_COL_SUM_H_

int* randomMatrix(int rows, int cols);
int* sequentialSum(int* matrix, int rows, int cols);
int* parallelSum(int* initial_matrix, int n, int m);

#endif  // MODULES_MPI_COL_SUM_COL_SUM_H_
