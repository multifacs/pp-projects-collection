// Copyright 2022 Shelepin Nikita
#ifndef MODULES_MPI_SLEEPING_BARBER_2_SLEEPING_BARBER_H_
#define MODULES_MPI_SLEEPING_BARBER_2_SLEEPING_BARBER_H_

#define SEAT_REQUEST 1
#define SEAT_RESPONSE 2
#define HAIRCUT_REQUEST 3
#define HAIRCUT 4

void barber(int rank, int client_count);
void client(int rank);
void queue(int seat_count, int runs);

#endif  // MODULES_MPI_SLEEPING_BARBER_2_SLEEPING_BARBER_H_
