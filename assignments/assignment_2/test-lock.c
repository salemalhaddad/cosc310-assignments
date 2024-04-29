#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define N 5

_Atomic bool forks_lock[N];

void* philosopher_test_and_set(void* num) {
    int phil = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", phil);
        sleep(1);

        while (atomic_exchange(&forks_lock[phil], true) || atomic_exchange(&forks_lock[(phil + 1) % N], true)) {
            atomic_store(&forks_lock[phil], false);
            atomic_store(&forks_lock[(phil + 1) % N], false);
            usleep(100000);
        }

        printf("Philosopher %d is eating...\n", phil);
        sleep(1);

        atomic_store(&forks_lock[phil], false);
        atomic_store(&forks_lock[(phil + 1) % N], false);

        printf("Philosopher %d finished eating and put down the forks.\n", phil);
        sleep(1);
    }
}

void test_and_set_solution() {
    for (int i = 0; i < N; i++) {
        forks_lock[i] = false;
    }

    pthread_t philosophers[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_test_and_set, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
}
