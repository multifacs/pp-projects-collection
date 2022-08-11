// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_HORIZ_SCHEM_HORIZ_SCHEM_H_
#define MODULES_MPI_HORIZ_SCHEM_HORIZ_SCHEM_H_
#include <mpi.h>

#include <iostream>
#include <random>
#include <vector>

std::vector<int> random_vector(int size);
std::vector<int> transposition(std::vector<int> b, int size);
std::vector<int> multiplication(std::vector<int> a, std::vector<int> b,
                                int size);
std::vector<int> multiplication_parallel(std::vector<int> A,
                                         const std::vector<int>& B, int data);
#endif  // MODULES_MPI_HORIZ_SCHEM_HORIZ_SCHEM_H_
