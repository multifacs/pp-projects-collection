// Copyright 2022 Shelepin Nikita
#ifndef MODULES_SEQ_SHELL_SORT_SHELL_SORT_H_
#define MODULES_SEQ_SHELL_SORT_SHELL_SORT_H_

#include <omp.h>

#include <random>

int* generate_vector(int n);
void shell_sort(int a[], int n, bool parallel = true);
void print_list(int a[], int n);
int check_list(int a[], int n);

#endif  // MODULES_SEQ_SHELL_SORT_SHELL_SORT_H_
