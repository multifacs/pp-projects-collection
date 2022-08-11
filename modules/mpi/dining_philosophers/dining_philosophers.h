// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_DINING_PHILOSOPHERS_DINING_PHILOSOPHERS_H_
#define MODULES_MPI_DINING_PHILOSOPHERS_DINING_PHILOSOPHERS_H_

void philosopher(int myrank, int runs);
void table(int myrank, int nprocs, int runs);

#define FORK_REQUEST 1
#define FORK_RESPONSE 2
#define FORK_RELEASE 3

#define HUNGRY 1
#define EATING 2
#define THINKING 3

#endif  // MODULES_MPI_DINING_PHILOSOPHERS_DINING_PHILOSOPHERS_H_
