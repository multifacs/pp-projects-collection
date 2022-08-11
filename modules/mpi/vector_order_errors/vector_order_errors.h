// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_VECTOR_ORDER_ERRORS_VECTOR_ORDER_ERRORS_H_
#define MODULES_MPI_VECTOR_ORDER_ERRORS_VECTOR_ORDER_ERRORS_H_

#include <vector>

std::vector<int> getRandomVector(int sz);
int getParallelOrderErrors(std::vector<int> global_vec);
int getSequentialOrderErrors(std::vector<int> vec);

#endif  // MODULES_MPI_VECTOR_ORDER_ERRORS_VECTOR_ORDER_ERRORS_H_
