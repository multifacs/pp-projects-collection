// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_TRAPEZ_METHOD_TRAPEZ_METHOD_H_
#define MODULES_MPI_TRAPEZ_METHOD_TRAPEZ_METHOD_H_

double getParallelOperations(double a, double b, int n,
    const std::function<double(double)>& f);
double getSequentialOperations(double a, double b, int n,
    const std::function<double(double)>& f);

#endif  // MODULES_MPI_TRAPEZ_METHOD_TRAPEZ_METHOD_H_
