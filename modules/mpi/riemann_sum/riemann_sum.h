// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_RIEMANN_SUM_RIEMANN_SUM_H_
#define MODULES_MPI_RIEMANN_SUM_RIEMANN_SUM_H_

#include <cmath>
#include <functional>
#include <utility>
#include <vector>

const double eps = 0.01;

double getSequentialIntegrals(
    const int n, const std::vector<std::pair<double, double>>& limits,
    const std::function<double(std::vector<double>)>& f);
double getParallelIntegrals(
    const int n, const std::vector<std::pair<double, double>>& limits,
    const std::function<double(std::vector<double>)>& f);
#endif  // MODULES_MPI_RIEMANN_SUM_RIEMANN_SUM_H_
