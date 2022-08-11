// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_RIBBON_HORIZONTAL_RIBBON_HORIZONTAL_H_
#define MODULES_MPI_RIBBON_HORIZONTAL_RIBBON_HORIZONTAL_H_

int* initEmptyMatrix(int rows, int cols);
int* getRandomMatrix(int rows, int cols);
void SequentialMatrixMultiplication(int* A, int ARows, int ACols,
    int* B, int BRows, int BCols, int* C);
void ParallelMatrixMultiplication(int* A, int ARows, int ACols,
    int* B, int BRows, int BCols, int* C);

#endif  // MODULES_MPI_RIBBON_HORIZONTAL_RIBBON_HORIZONTAL_H_
