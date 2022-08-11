// Copyright 2022 Shelepin Nikita
#ifndef MODULES_OMP_SIMPSON_SIMPSON_H_
#define MODULES_OMP_SIMPSON_SIMPSON_H_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

double getOMPSimpson(
    const std::function<double(std::vector<double>)>& f,
    const std::vector<std::pair<double, double>>& limits,
    const std::vector<int>& n);

#endif  // MODULES_OMP_SIMPSON_SIMPSON_H_
