// Copyright 2022 Shelepin Nikita
#ifndef MODULES_OMP_RADIX_INT_SIMPLE_MERGE_RADIX_INT_SIMPLE_MERGE_H_
#define MODULES_OMP_RADIX_INT_SIMPLE_MERGE_RADIX_INT_SIMPLE_MERGE_H_

#include <algorithm>
#include <vector>

using INT_VEC = std::vector<int>;

INT_VEC getRandomVec(int n);
void radixSortSimpleMerge(INT_VEC* vec, int parts, bool parallel = true,
                          bool parallel_merge = false);
void printVec(const INT_VEC& vec);
bool checkOrder(const INT_VEC& vec);

#endif  // MODULES_OMP_RADIX_INT_SIMPLE_MERGE_RADIX_INT_SIMPLE_MERGE_H_
