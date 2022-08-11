// Copyright 2022 Shelepin Nikita
#include <gtest/gtest.h>
#include <omp.h>

#include "./qsort_simple_merge.h"

void measureTime(INT_VEC* vec1, INT_VEC* vec2, int parts) {
  double start = omp_get_wtime();
  quickSortSimpleMerge(vec1, parts, false);
  double end = omp_get_wtime();
  double seq_time = end - start;

  start = omp_get_wtime();
  quickSortSimpleMerge(vec2, parts);
  end = omp_get_wtime();
  double par_time = end - start;

  std::cout << "seq: " << seq_time << "\n";
  std::cout << "par: " << par_time << "\n";
  std::cout << "speed: " << seq_time / par_time << "\n\n";
}

TEST(QUICK_SORT_SIMPLE_MERGE_OMP, TEST_1) {
  int n = 10;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  quickSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(QUICK_SORT_SIMPLE_MERGE_OMP, TEST_2) {
  int n = 11;
  int parts = 11;
  INT_VEC vec = getRandomVec(n);
  quickSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(QUICK_SORT_SIMPLE_MERGE_OMP, TEST_3) {
  int n = 12;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  quickSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(QUICK_SORT_SIMPLE_MERGE_OMP, TEST_4) {
  int n = 13;
  int parts = 3;
  INT_VEC vec = getRandomVec(n);
  quickSortSimpleMerge(&vec, parts);
  // printVec(vec);
  ASSERT_TRUE(checkOrder(vec));
}

TEST(QUICK_SORT_SIMPLE_MERGE_OMP, TEST_5) {
  int runs = 3;
  int n = 100;
  int parts = omp_get_max_threads();
  for (int i = 0; i < runs; i++) {
    std::cout << "n: " << n << "\n";
    std::cout << "parts: " << parts << "\n";
    INT_VEC vec1 = getRandomVec(n);
    INT_VEC vec2(vec1);

    measureTime(&vec1, &vec2, parts);
    n *= 30;
    // parts += 10;
  }
}
