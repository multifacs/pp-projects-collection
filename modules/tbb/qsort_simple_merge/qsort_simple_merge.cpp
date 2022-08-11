// Copyright 2022 Shelepin Nikita
#include "../../../modules/tbb/qsort_simple_merge/qsort_simple_merge.h"

#include <tbb/tbb.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>

INT_VEC getRandomVec(int n) {
  std::random_device dev;
  static std::mt19937 gen(dev());

  INT_VEC vec(n);

  std::generate(vec.begin(), vec.end(), [] { return gen() % 1000; });

  return vec;
}

void quickSort(INT_VEC::iterator begin, INT_VEC::iterator end) {
  if (begin != end) {
    INT_VEC::iterator middle = std::partition(
        begin, end,
        std::bind2nd(
            std::less<
                typename std::iterator_traits<INT_VEC::iterator>::value_type>(),
            *begin));
    quickSort(begin, middle);

    INT_VEC::iterator new_middle = begin;
    quickSort(++new_middle, end);
  }
}

INT_VEC mergeVecs(const INT_VEC& arr1, const INT_VEC& arr2) {
  int n1 = static_cast<int>(arr1.size());
  int n2 = static_cast<int>(arr2.size());

  int i = 0, j = 0, k = 0;

  INT_VEC arr3(n1 + n2);

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }

  while (i < n1) arr3[k++] = arr1[i++];
  while (j < n2) arr3[k++] = arr2[j++];

  return arr3;
}

void radixSortSimpleMerge(INT_VEC* vec, int parts, bool parallel) {
  std::vector<INT_VEC> vecs(parts);
  int grainsize = static_cast<int>((*vec).size()) / parts;

  if (!grainsize) {
    quickSort(vec->begin(), vec->end());
    return;
  }

  for (int i = 0; i < parts - 1; i++) {
    INT_VEC::const_iterator first = (*vec).begin() + grainsize * i;
    INT_VEC::const_iterator last = (*vec).begin() + grainsize * (i + 1);

    vecs[i] = INT_VEC(first, last);
  }
  vecs.back() = INT_VEC((*vec).begin() + grainsize * (parts - 1), (*vec).end());

  if (parallel) {
    tbb::task_group group;
    for (int i = 0; i < parts; i++) {
      group.run([&vecs, i]() { quickSort(vecs[i].begin(), vecs[i].end()); });
    }
    group.wait();
  } else {
    for (auto&& elem : vecs) {
      quickSort(elem.begin(), elem.end());
    }
  }

  (*vec) = vecs[0];

  for (auto iter = vecs.begin() + 1; iter != vecs.end(); ++iter) {
    (*vec) = mergeVecs((*vec), *iter);
  }
}

void printVec(const INT_VEC& vec) {
  for (auto elem : vec) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

bool checkOrder(const INT_VEC& vec) {
  for (auto iter = vec.begin(); iter != std::prev(vec.end()); ++iter) {
    if (*iter > *(iter + 1)) {
      return false;
    }
  }
  return true;
}
