// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_SIMPSON_SIMPSON_H_
#define MODULES_MPI_SIMPSON_SIMPSON_H_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

double getSequentialSimpson(
    const std::function<double(std::vector<double>)>& f,
    const std::vector<std::pair<double, double>>& limits,
    const std::vector<int>& n);

double getParallelSimpson(const std::function<double(std::vector<double>)>& f,
                          const std::vector<std::pair<double, double>>& limits,
                          const std::vector<int>& n);

#endif  // MODULES_MPI_SIMPSON_SIMPSON_H_
