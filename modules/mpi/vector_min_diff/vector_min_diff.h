// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_VECTOR_MIN_DIFF_VECTOR_MIN_DIFF_H_
#define MODULES_MPI_VECTOR_MIN_DIFF_VECTOR_MIN_DIFF_H_

#include <vector>

std::vector<int> getRandomVector(int sz);
int* getParallelMinDiff(std::vector<int> global_vec);
int* getSequentialMinDiff(std::vector<int> vec);

#endif  // MODULES_MPI_VECTOR_MIN_DIFF_VECTOR_MIN_DIFF_H_
