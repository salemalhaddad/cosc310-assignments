#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memcpy

#define NUM_BLOCKS 5
#define NUM_PROCESSES 4

int blocks[] = {100, 500, 200, 300, 600};
int process[] = {212, 417, 112, 426};

// Arrays to store block ID of the block allocated to a process
int *bestFitAllocation, *worstFitAllocation, *firstFitAllocation;
int temp_blocks[NUM_BLOCKS];

void initializeAllocations() {
    bestFitAllocation = malloc(sizeof(int) * NUM_PROCESSES);
    worstFitAllocation = malloc(sizeof(int) * NUM_PROCESSES);
    firstFitAllocation = malloc(sizeof(int) * NUM_PROCESSES);
    for (int i = 0; i < NUM_PROCESSES; i++) {
        bestFitAllocation[i] = -1;
        worstFitAllocation[i] = -1;
        firstFitAllocation[i] = -1;
    }
}

void bestFit() {
    memcpy(temp_blocks, blocks, NUM_BLOCKS * sizeof(int));

    for (int i = 0; i < NUM_PROCESSES; i++) {
        int best_idx = -1;
        for (int j = 0; j < NUM_BLOCKS; j++) {
            if (temp_blocks[j] >= process[i]) {
                if (best_idx == -1 || temp_blocks[j] < temp_blocks[best_idx]) {
                    best_idx = j;
                }
            }
        }
        if (best_idx != -1) {
            bestFitAllocation[i] = best_idx;
            temp_blocks[best_idx] -= process[i];
        }
    }
}

void worstFit() {
    memcpy(temp_blocks, blocks, NUM_BLOCKS * sizeof(int));

    for (int i = 0; i < NUM_PROCESSES; i++) {
        int worst_idx = -1;
        for (int j = 0; j < NUM_BLOCKS; j++) {
            if (temp_blocks[j] >= process[i]) {
                if (worst_idx == -1 || temp_blocks[j] > temp_blocks[worst_idx]) {
                    worst_idx = j;
                }
            }
        }
        if (worst_idx != -1) {
            worstFitAllocation[i] = worst_idx;
            temp_blocks[worst_idx] -= process[i];
        }
    }
}

void firstFit() {
    memcpy(temp_blocks, blocks, NUM_BLOCKS * sizeof(int));

    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_BLOCKS; j++) {
            if (temp_blocks[j] >= process[i]) {
                firstFitAllocation[i] = j;
                temp_blocks[j] -= process[i];
                break;
            }
        }
    }
}

void printAllocations() {
    printf("\n\tProcess ID \tProcess Size \tBest-Fit \tWorst-Fit \tFirst-Fit \n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("\t%d \t\t", i + 1);
        printf("%d \t\t", process[i]);

        if (bestFitAllocation[i] != -1)
            printf("%d \t\t", bestFitAllocation[i] + 1);
        else
            printf("Not Allocated \t");

        if (worstFitAllocation[i] != -1)
            printf("%d \t\t", worstFitAllocation[i] + 1);
        else
            printf("Not Allocated \t");

        if (firstFitAllocation[i] != -1)
            printf("%d \t\t", firstFitAllocation[i] + 1);
        else
            printf("Not Allocated \t");

        printf("\n");
    }
    printf("\n");
}

int main() {
    printf("\n\tBlock ID \tBlock Size\n");
    for (int i = 0; i < NUM_BLOCKS; i++) {
        printf("\t%d \t\t%d \n", i + 1, blocks[i]);
    }

    initializeAllocations();

    bestFit();
    worstFit();
    firstFit();

    printAllocations();

    free(bestFitAllocation);
    free(worstFitAllocation);
    free(firstFitAllocation);

    return 0;
}
