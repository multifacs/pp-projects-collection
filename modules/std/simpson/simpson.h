// Copyright 2022 Shelepin Nikita
#ifndef MODULES_STD_SIMPSON_SIMPSON_H_
#define MODULES_STD_SIMPSON_SIMPSON_H_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

double getSTDSimpson(const std::function<double(std::vector<double>)>& f,
                     const std::vector<std::pair<double, double>>& limits,
                     const std::vector<int>& n);

double getSeqSimpson(const std::function<double(std::vector<double>)>& f,
                     const std::vector<std::pair<double, double>>& limits,
                     const std::vector<int>& n);

#endif  // MODULES_STD_SIMPSON_SIMPSON_H_
