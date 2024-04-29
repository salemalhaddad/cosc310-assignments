#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

bool flag[N];
int turn = 0;

void* philosopher_peterson(void* num) {
    int phil = *(int*)num;
    int next = (phil + 1) % N;

    while (1) {
        printf("Philosopher %d is thinking...\n", phil);
        sleep(1);

        flag[phil] = true;
        turn = next;

        while (flag[next] && turn == next) {
            // Do nothing, just wait
        }

        printf("Philosopher %d is eating...\n", phil);
        sleep(1);

        flag[phil] = false;

        printf("Philosopher %d finished eating and put down the forks.\n", phil);
        sleep(1);
    }
}

void petersons_solution() {
    for (int i = 0; i < N; i++) {
        flag[i] = false;
    }

    pthread_t philosophers[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_peterson, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
}
