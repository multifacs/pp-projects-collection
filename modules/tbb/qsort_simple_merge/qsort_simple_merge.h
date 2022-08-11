// Copyright 2022 Shelepin Nikita
#ifndef MODULES_TBB_QSORT_SIMPLE_MERGE_QSORT_SIMPLE_MERGE_H_
#define MODULES_TBB_QSORT_SIMPLE_MERGE_QSORT_SIMPLE_MERGE_H_

#include <algorithm>
#include <vector>

using INT_VEC = std::vector<int>;

INT_VEC getRandomVec(int n);
void radixSortSimpleMerge(INT_VEC* vec, int parts, bool parallel = true);
void printVec(const INT_VEC& vec);
bool checkOrder(const INT_VEC& vec);

#endif  // MODULES_TBB_QSORT_SIMPLE_MERGE_QSORT_SIMPLE_MERGE_H_
