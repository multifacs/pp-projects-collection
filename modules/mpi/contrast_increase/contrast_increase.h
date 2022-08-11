// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_CONTRAST_INCREASE_CONTRAST_INCREASE_H_
#define MODULES_MPI_CONTRAST_INCREASE_CONTRAST_INCREASE_H_

double* getRandomImage(int width, int height);
double* getSequentialContrastIncrease(double* image, int width, int height,
                                      double contrast);
double* getParallelContrastIncrease(double* image, int width, int height,
                                    double contrast);

#endif  // MODULES_MPI_CONTRAST_INCREASE_CONTRAST_INCREASE_H_
