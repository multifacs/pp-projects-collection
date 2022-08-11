// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_REDUCE_REDUCE_H_
#define MODULES_MPI_REDUCE_REDUCE_H_

#include <mpi.h>

#include <cstring>
#include <iostream>

int my_reduce(void*, void*, int, MPI_Datatype, MPI_Op, int, MPI_Comm);

#endif  // MODULES_MPI_REDUCE_REDUCE_H_
