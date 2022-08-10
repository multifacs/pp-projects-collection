// Copyright 2021 Naginaylo Dmitriy
#ifndef MODULES_TASK_1_NAGINAYLO_D_VECTOR_ORDER_ERRORS_VECTOR_ORDER_ERRORS_H_
#define MODULES_TASK_1_NAGINAYLO_D_VECTOR_ORDER_ERRORS_VECTOR_ORDER_ERRORS_H_

#include <vector>

std::vector<int> getRandomVector(int sz);
int getParallelOrderErrors(std::vector<int> global_vec);
int getSequentialOrderErrors(std::vector<int> vec);

#endif  // MODULES_TASK_1_NAGINAYLO_D_VECTOR_ORDER_ERRORS_VECTOR_ORDER_ERRORS_H_
