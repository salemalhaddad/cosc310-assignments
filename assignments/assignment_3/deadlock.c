#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCE_TYPES 5

int avail[NUM_RESOURCE_TYPES];  // Available resources
int work[NUM_RESOURCE_TYPES];  // Work array to track available resources in safe sequence

struct process {
    int allocation[NUM_RESOURCE_TYPES];
    int max[NUM_RESOURCE_TYPES];
    int need[NUM_RESOURCE_TYPES];
    bool finish;
} p[NUM_PROCESSES];

void initialize_processes() {
    // Sample initialization
    int allocations[NUM_PROCESSES][NUM_RESOURCE_TYPES] = {
        {0, 1, 0, 3, 2},
        {1, 0, 1, 1, 1},
        {1, 2, 1, 0, 0},
        {0, 0, 0, 2, 1},
    };

    int max_req[NUM_PROCESSES][NUM_RESOURCE_TYPES] = {
        {7, 5, 3, 4, 3},
        {3, 2, 2, 2, 1},
        {3, 4, 4, 1, 1},
        {1, 2, 2, 2, 3},
    };

    for (int i = 0; i < NUM_PROCESSES; i++) {
        p[i].finish = false;
        for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
            p[i].allocation[j] = allocations[i][j];
            p[i].max[j] = max_req[i][j];
            p[i].need[j] = max_req[i][j] - allocations[i][j];
        }
    }

    int available[NUM_RESOURCE_TYPES] = {3, 3, 2, 1, 4};
    for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
        avail[j] = available[j];
        work[j] = avail[j];
    }
}

bool is_safe_state() {
    bool safe = false;
    int safe_sequence[NUM_PROCESSES];
    int idx = 0;

    while (idx < NUM_PROCESSES) {
        safe = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!p[i].finish) {
                bool enough_resources = true;
                for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
                    if (p[i].need[j] > work[j]) {
                        enough_resources = false;
                        break;
                    }
                }

                if (enough_resources) {
                    for (int j = 0; j < NUM_RESOURCE_TYPES; j++) {
                        work[j] += p[i].allocation[j];
                    }
                    safe_sequence[idx++] = i;
                    p[i].finish = true;
                    safe = true;
                    break;
                }
            }
        }

        if (!safe) break;
    }

    if (idx == NUM_PROCESSES) {
        printf("Safe State: Safe Sequence is: ");
        for (int i = 0; i < NUM_PROCESSES; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
        return true;
    } else {
        printf("Not in a safe state. Potential deadlock.\n");
        return false;
    }
}

int main() {
    initialize_processes();

    if (!is_safe_state()) {
        printf("System is in a deadlock or an unsafe state.\n");
    }

    return 0;
}
