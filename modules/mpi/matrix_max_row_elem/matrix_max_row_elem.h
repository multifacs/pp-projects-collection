// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_MATRIX_MAX_ROW_ELEM_MATRIX_MAX_ROW_ELEM_H_
#define MODULES_MPI_MATRIX_MAX_ROW_ELEM_MATRIX_MAX_ROW_ELEM_H_

int* randomMatrix(int n, int m);
int* sequentialMax(int* matrix, int n, int m);
int* parallelMax(int* global_matrix, int n, int m);

#endif  // MODULES_MPI_MATRIX_MAX_ROW_ELEM_MATRIX_MAX_ROW_ELEM_H_
