// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_IMAGE_SMOOTHING_IMAGE_SMOOTHING_H_
#define MODULES_MPI_IMAGE_SMOOTHING_IMAGE_SMOOTHING_H_

int* getRandomImage(int width, int height);
int* getSequentialGauss(int* image, int width, int height, int radius);
int* getParallelGauss(int* image, int width, int height, int radius);

#endif  // MODULES_MPI_IMAGE_SMOOTHING_IMAGE_SMOOTHING_H_
