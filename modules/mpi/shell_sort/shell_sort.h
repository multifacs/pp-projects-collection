// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_SHELL_SORT_SHELL_SORT_H_
#define MODULES_MPI_SHELL_SORT_SHELL_SORT_H_

#include <vector>

std::vector<int> getRandomVector(int sz);
void getSequentialShellSort(std::vector<int>* vec);
void getParallelShellSort(std::vector<int>* arr);

#endif  // MODULES_MPI_SHELL_SORT_SHELL_SORT_H_
