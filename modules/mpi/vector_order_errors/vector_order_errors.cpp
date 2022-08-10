// Copyright 2021 Naginaylo Dmitriy
#include "../../../modules/task_1/naginaylo_d_vector_order_errors/vector_order_errors.h"

#include <mpi.h>

#include <random>
#include <vector>
#include <iostream>

std::vector<int> getRandomVector(int sz) {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_int_distribution<> distrib(0, sz - 2);
  std::vector<int> vec(sz);

  int errors = distrib(gen) / 2;
  // std::cout << "Errors: " << errors << std::endl;

  for (int i = 0; i < sz; i++) {
    vec[i] = i + 1;
  }

  // std::cout << "Vec: " << std::endl;
  //for (int i = 0; i < sz; i++) {
  //  std::cout << vec[i] << ' ';
  //}
  //std::cout << std::endl;

  for (int i = 0; i < errors; i++) {
    int idx = distrib(gen);
    // std::cout << "idx: " << idx << std::endl;
    vec[idx] = vec[idx + 1] + 1;
  }

  // std::cout << std::endl;
  // std::cout << "Result: " << std::endl;
  /*for (int i = 0; i < sz; i++) {
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl << std::endl;*/

  return vec;
}

int getSequentialOrderErrors(std::vector<int> vec) {
  int errors = 0;
  
  if (vec.size() != 0) {
    for (int i = 0; i < static_cast<int>(vec.size()) - 1; i++) {
      if (vec[i] > vec[i + 1]) {
        errors++;
      }
    }
  }

  return errors;
}

int getParallelOrderErrors(std::vector<int> global_vec) {
  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  int vector_size;
  if (rank == 0) {
    vector_size = global_vec.size();
  }
  MPI_Bcast(&vector_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

  int delta = (vector_size + size - 1) / size;
  int rem = (vector_size + size - 1) % size;

  std::vector<int> local_vector;

  if (delta && size != 1) {
    int local_errors = 0;
    int pos = delta + rem - 1;

    if (rank == 0) {
      for (int proc = 1; proc < size; proc++) {
        MPI_Send(global_vec.data() + pos, delta, MPI_INT, proc, 0,
                 MPI_COMM_WORLD);
        pos += delta - 1;
      }

      local_vector = std::vector<int>(global_vec.begin(),
                                      global_vec.begin() + delta + rem);
    } else {
      local_vector = std::vector<int>(delta);
      MPI_Recv(local_vector.data(), delta, MPI_INT, 0, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
    }

    local_errors = getSequentialOrderErrors(local_vector);

    int global_errors = 0;
    MPI_Reduce(&local_errors, &global_errors, 1, MPI_INT, MPI_SUM, 0,
               MPI_COMM_WORLD);

    return global_errors;
  } else {
    if (rank == 0) {
      return getSequentialOrderErrors(global_vec);
    } else {
      return 0;
    }
  }
}
