#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCE_TYPES 5

int avail[NUM_RESOURCE_TYPES];
int work[NUM_RESOURCE_TYPES];

struct process {
    int allocation[NUM_RESOURCE_TYPES];
    int max[NUM_RESOURCE_TYPES];
    int need[NUM_RESOURCE_TYPES];
    bool finish;
} p[NUM_PROCESSES];

bool isSafeState() {
    bool finish[NUM_PROCESSES] = {false};
    int done, cnt = 0;

    for (int i = 0; i < NUM_RESOURCE_TYPES; i++) {
        work[i] = avail[i];
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }

    while (cnt < NUM_PROCESSES) {
        bool found = false;

        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!p[i].finish) {
                int j;
                for (j = 0; j < NUM_RESOURCE_TYPES; j++) {
                    if (p[i].need[j] > work[j]) {
                        break;
                    }
                }

                if (j == NUM_RESOURCE_TYPES) {
                    for (int k = 0; k < NUM_RESOURCE_TYPES; k++) {
                        work[k] += p[i].allocation[k];
                    }

                    finish[i] = true;
                    found = true;
                    cnt++;
                }
            }
        }

        if (!found) {
            return false; // Deadlock detected
        }
    }

    return true; // System is in a safe state
}

int main() {
    // Initialize resources
    for (int i = 0; i < NUM_RESOURCE_TYPES; i++) {
        printf("Enter the number of available instances for resource %d: ", i);
        scanf("%d", &avail[i]);
    }

    // Input allocated resources and maximum need for each process
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("For process P%d:\n", i);

        for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
            printf("Enter the number of allocated instances for resource %d: ", j);
            scanf("%d", &p[i].allocation[j]);
        }

        for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
            printf("Enter the maximum need for resource %d: ", j);
            scanf("%d", &p[i].max[j]);
        }
    }

    if (isSafeState()) {
        printf("System is in a safe state.\n");
        printf("Safe sequence: ");

        for (int i = 0; i < NUM_PROCESSES; i++) {
            printf("P%d ", i);
        }

        printf("\n");
    } else {
        printf("Deadlock detected. Processes causing deadlock: ");
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!p[i].finish) {
                printf("P%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}
