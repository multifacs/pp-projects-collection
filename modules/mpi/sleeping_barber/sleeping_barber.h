// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_SLEEPING_BARBER_SLEEPING_BARBER_H_
#define MODULES_MPI_SLEEPING_BARBER_SLEEPING_BARBER_H_

void wait(double s);
void Barber(int line_length, int size);
void Client(int rank);

#endif  // MODULES_MPI_SLEEPING_BARBER_SLEEPING_BARBER_H_
