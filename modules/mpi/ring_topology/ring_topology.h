// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_RING_TOPOLOGY_RING_TOPOLOGY_H_
#define MODULES_MPI_RING_TOPOLOGY_RING_TOPOLOGY_H_
#include <mpi.h>

MPI_Comm getRingTopology(const MPI_Comm comm);

#endif  // MODULES_MPI_RING_TOPOLOGY_RING_TOPOLOGY_H_
