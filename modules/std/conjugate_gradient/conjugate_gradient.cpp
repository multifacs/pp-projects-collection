// Copyright 2022 Shelepin Nikita
#include "../../../modules/std/conjugate_gradient/conjugate_gradient.h"

#include <omp.h>

#include <iostream>
#include <random>
#include <vector>

#include "../../../3rdparty/unapproved/unapproved.h"

vec generateRandomVector(int size) {
  std::random_device dev;
  static std::mt19937 gen(dev());

  vec data(size);
  std::generate(data.begin(), data.end(), []() { return gen() % 100; });
  return data;
}

matrix generateMatrix(vec v) {
  int size = v.size();
  matrix C = std::vector<vec>(size, vec(size, 0));

  for (int row = 0; row < size; row++)
    for (int col = 0; col < size; col++) {
      if (row == col)  // special case for the main diagonal
        C[row][col] = v[0];
      else if (row + col < size)  // normal case for small indexes
        C[row][col] = v[row + col];
      else  // special case for large indexes
        C[row][col] = v[2 * (size - 1) - (row + col)];
    }

  return C;
}

void printError(const vec& B, const vec& check, int n) {
  double error = 0;
  for (int i = 0; i < n; i++) {
    error += std::fabs(B[i] - check[i]);
  }
  error /= n;
  std::cout << "Error: " << std::fixed << error << "\n";
}

//======================================================================

void print(const std::string& title, const vec& V) {
  std::cout << title << '\n';

  int n = V.size();
  for (int i = 0; i < n; i++) {
    double x = V[i];
    if (fabs(x) < NEARZERO) x = 0.0;
    std::cout << x << '\t';
  }
  std::cout << '\n';
}

//======================================================================

void print(const std::string& title, const matrix& A) {
  std::cout << title << '\n';

  int m = A.size(), n = A[0].size();  // A is an m x n matrix
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      double x = A[i][j];
      if (fabs(x) < NEARZERO) x = 0.0;
      std::cout << x << '\t';
    }
    std::cout << '\n';
  }
}

double scalarProduct(const vec& V, const vec& U) {
  double sclr_res = 0;
  // #pragma omp parallel for schedule(static, 1) reduction(+ : sclr_res)
  for (int i = 0; i < static_cast<int>(V.size()); ++i) {
    sclr_res += V[i] * U[i];
  }
  return sclr_res;
}

vec matrixTimesVector(const matrix& A, const vec& V) {
  vec C(V.size());
  for (int i = 0; i < static_cast<int>(V.size()); ++i) {
    C[i] = 0;
    for (int j = 0; j < static_cast<int>(V.size()); ++j) {
      C[i] += A[i][j] * V[j];
    }
  }
  return C;
}

vec matrixTimesVectorParallel(const matrix& A, const vec& V) {
  vec C(V.size());

  const int thread_num = std::thread::hardware_concurrency();

  auto thread_func = [&C, &V, &A](int begin, int end, int index) {
    for (int i = begin; i < end; ++i) {
      C[i] = 0;
      for (int j = 0; j < static_cast<int>(V.size()); ++j) {
        C[i] += A[i][j] * V[j];
      }
    }
  };

  std::vector<std::thread> threads(thread_num);
  int delta = static_cast<int>(V.size()) / thread_num;

  for (int thread = 0; thread < thread_num; ++thread) {
    int begin = delta * thread;
    int end = delta * (thread + 1);

    if (thread != thread_num - 1) {
      threads[thread] = std::thread(thread_func, begin, end, thread);
    } else {
      threads[thread] = std::thread(thread_func, delta * (thread_num - 1),
                                    static_cast<int>(V.size()), thread_num - 1);
    }
  }

  for (auto&& i : threads) {
    i.join();
  }

  return C;
}

vec conjugateGradientSolver(const matrix& A, const vec& V) {
  int size_n = A.size();

  vec Rold(size_n);
  vec R(size_n);
  int flag = 0;
  double prov_sqrt = 0;
  double epsilon = 0.01, b = 0.0, alfa = 0.0;
  vec X(size_n);
  for (int i = 0; i < size_n; i++) {
    X[i] = 1;
  }
  vec AP = matrixTimesVector(A, X);

  for (int i = 0; i < size_n; i++) {
    Rold[i] = V[i] - AP[i];
  }
  vec P(Rold);
  do {
    flag++;
    AP = matrixTimesVector(A, P);
    alfa = scalarProduct(Rold, Rold) / scalarProduct(P, AP);
    for (int i = 0; i < size_n; i++) {
      X[i] += alfa * P[i];
      R[i] = Rold[i] - alfa * AP[i];
    }
    b = scalarProduct(R, R) / scalarProduct(Rold, Rold);
    prov_sqrt = sqrt(scalarProduct(R, R));
    for (int j = 0; j < size_n; j++) {
      P[j] = R[j] + b * P[j];
    }
    Rold = R;
  } while ((prov_sqrt > epsilon) && (flag <= size_n));
  return X;
}

vec conjugateGradientSolverParallel(const matrix& A, const vec& V) {
  int size_n = A.size();

  vec Rold(size_n);
  vec R(size_n);
  int flag = 0;
  double prov_sqrt = 0;
  double epsilon = 0.01, b = 0.0, alfa = 0.0;
  vec X(size_n);
  for (int i = 0; i < size_n; i++) {
    X[i] = 1;
  }
  vec AP = matrixTimesVectorParallel(A, X);

  for (int i = 0; i < size_n; i++) {
    Rold[i] = V[i] - AP[i];
  }
  vec P(Rold);
  do {
    flag++;
    AP = matrixTimesVectorParallel(A, P);
    alfa = scalarProduct(Rold, Rold) / scalarProduct(P, AP);
    for (int i = 0; i < size_n; i++) {
      X[i] += alfa * P[i];
      R[i] = Rold[i] - alfa * AP[i];
    }
    b = scalarProduct(R, R) / scalarProduct(Rold, Rold);
    prov_sqrt = sqrt(scalarProduct(R, R));
    for (int j = 0; j < size_n; j++) {
      P[j] = R[j] + b * P[j];
    }
    Rold = R;
  } while ((prov_sqrt > epsilon) && (flag <= size_n));
  return X;
}
