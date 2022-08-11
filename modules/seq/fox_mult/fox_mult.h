// Copyright 2022 Shelepin Nikita
#ifndef MODULES_SEQ_FOX_MULT_FOX_MULT_H_
#define MODULES_SEQ_FOX_MULT_FOX_MULT_H_

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

#endif  // MODULES_SEQ_FOX_MULT_FOX_MULT_H_
