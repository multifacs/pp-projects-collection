// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_RIBBON_VERTICAL_RIBBON_VERTICAL_H_
#define MODULES_MPI_RIBBON_VERTICAL_RIBBON_VERTICAL_H_

int* initEmptyMatrix(int rows);
int* getRandomMatrix(int rows, int cols);
void SequentialMatrixMultiplication(const int* A, const int ARows,
                                    const int ACols, const int* B,
                                    const int BRows, int* C);
void ParallelMatrixMultiplication(const int* A, const int ARows,
                                  const int ACols, const int* B,
                                  const int BRows, int* C);

#endif  // MODULES_MPI_RIBBON_VERTICAL_RIBBON_VERTICAL_H_
