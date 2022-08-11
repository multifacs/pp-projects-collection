// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_JACOBY_METHOD_JACOBY_METHOD_H_
#define MODULES_MPI_JACOBY_METHOD_JACOBY_METHOD_H_

#include <vector>

const double eps = 0.0001;
const int max_iterations = 100;

std::vector<double> getDiagonallyDominantMatrix(int size);
std::vector<double> getB(int size);

double getError(std::vector<double> A, std::vector<double> x,
                std::vector<double> b);

std::vector<double> getJacobiSequential(std::vector<double> A,
                                        std::vector<double> b, int size);
std::vector<double> getJacobiParallel(std::vector<double> A,
                                      std::vector<double> b, int size);

#endif  // MODULES_MPI_JACOBY_METHOD_JACOBY_METHOD_H_
