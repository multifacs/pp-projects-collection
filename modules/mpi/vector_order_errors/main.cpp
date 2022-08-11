// Copyright 2022 Shelepin Nikita
#include <gtest/gtest.h>
#include <vector>
#include "./vector_order_errors.h"
#include <gtest-mpi-listener.hpp>

TEST(ORDER_ERRORS_MPI, TEST_1) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> global_vec;
    const int vector_size = 10;

    if (rank == 0) {
      global_vec = getRandomVector(vector_size);
    }

    int parallel_result = getParallelOrderErrors(global_vec);

    if (rank == 0) {
      int reference_result = getSequentialOrderErrors(global_vec);
      std::cout << "Sequential result: " << reference_result << std::endl;
      std::cout << "Parallel result: " << parallel_result << std::endl;
      ASSERT_EQ(reference_result, parallel_result);
    }
}

TEST(ORDER_ERRORS_MPI, TEST_2) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int vector_size = 20;

  if (rank == 0) {
    global_vec = getRandomVector(vector_size);
  }

  int parallel_result = getParallelOrderErrors(global_vec);

  if (rank == 0) {
    int reference_result = getSequentialOrderErrors(global_vec);
    std::cout << "Sequential result: " << reference_result << std::endl;
    std::cout << "Parallel result: " << parallel_result << std::endl;
    ASSERT_EQ(reference_result, parallel_result);
  }
}

TEST(ORDER_ERRORS_MPI, TEST_3) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int vector_size = 50;

  if (rank == 0) {
    global_vec = getRandomVector(vector_size);
  }

  int parallel_result = getParallelOrderErrors(global_vec);

  if (rank == 0) {
    int reference_result = getSequentialOrderErrors(global_vec);
    std::cout << "Sequential result: " << reference_result << std::endl;
    std::cout << "Parallel result: " << parallel_result << std::endl;
    ASSERT_EQ(reference_result, parallel_result);
  }
}

TEST(ORDER_ERRORS_MPI, TEST_4) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int vector_size = 100;

  if (rank == 0) {
    global_vec = getRandomVector(vector_size);
  }

  int parallel_result = getParallelOrderErrors(global_vec);

  if (rank == 0) {
    int reference_result = getSequentialOrderErrors(global_vec);
    std::cout << "Sequential result: " << reference_result << std::endl;
    std::cout << "Parallel result: " << parallel_result << std::endl;
    ASSERT_EQ(reference_result, parallel_result);
  }
}

TEST(ORDER_ERRORS_MPI, TEST_5) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int vector_size = 200;

  if (rank == 0) {
    global_vec = getRandomVector(vector_size);
  }

  int parallel_result = getParallelOrderErrors(global_vec);

  if (rank == 0) {
    int reference_result = getSequentialOrderErrors(global_vec);
    std::cout << "Sequential result: " << reference_result << std::endl;
    std::cout << "Parallel result: " << parallel_result << std::endl;
    ASSERT_EQ(reference_result, parallel_result);
  }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    MPI_Init(&argc, &argv);

    ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
    return RUN_ALL_TESTS();
}
