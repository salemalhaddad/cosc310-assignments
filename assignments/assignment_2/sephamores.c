#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];

void* philosopher(void* num) {
    int phil = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", phil);
        sleep(1);

        sem_wait(&forks[phil]);
        sem_wait(&forks[(phil + 1) % N]);

        printf("Philosopher %d is eating...\n", phil);
        sleep(1);

        sem_post(&forks[phil]);
        sem_post(&forks[(phil + 1) % N]);

        printf("Philosopher %d finished eating and put down the forks.\n", phil);
        sleep(1);
    }
}

void semaphores_solution() {
    for (int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    pthread_t philosophers[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        sem_destroy(&forks[i]);
    }
}
