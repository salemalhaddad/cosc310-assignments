#include <pthread.h>
#define N 5

pthread_mutex_t forks[N];

void* philosopher_mutex(void* num) {
    int phil = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", phil);
        sleep(1);

        pthread_mutex_lock(&forks[phil]);
        pthread_mutex_lock(&forks[(phil + 1) % N]);

        printf("Philosopher %d is eating...\n", phil);
        sleep(1);

        pthread_mutex_unlock(&forks[phil]);
        pthread_mutex_unlock(&forks[(phil + 1) % N]);

        printf("Philosopher %d finished eating and put down the forks.\n", phil);
        sleep(1);
    }
}

void mutex_locks_solution() {
    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    pthread_t philosophers[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_mutex, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
}
