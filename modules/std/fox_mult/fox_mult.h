// Copyright 2022 Shelepin Nikita
#ifndef MODULES_STD_FOX_MULT_FOX_MULT_H_
#define MODULES_STD_FOX_MULT_FOX_MULT_H_

#include <random>
#include <vector>

std::vector<std::vector<double>> getRandom(int n);
void multiply(std::vector<std::vector<double>>* C,
              const std::vector<std::vector<double>>& A,
              const std::vector<std::vector<double>>& B);
void foxMultiplication(std::vector<std::vector<double>>* C,
                       const std::vector<std::vector<double>>& A,
                       const std::vector<std::vector<double>>& B,
                       int block_size);
void foxMultiplicationParallel(std::vector<std::vector<double>>* C,
                               const std::vector<std::vector<double>>& A,
                               const std::vector<std::vector<double>>& B);

#endif  // MODULES_STD_FOX_MULT_FOX_MULT_H_
