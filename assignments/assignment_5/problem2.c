#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 4
#define MAX_PAGES 12

void optimal(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1, -1};
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            page_faults++;
            int replace_idx = -1, farthest = i;
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    replace_idx = j;
                    break;
                }

                int k;
                for (k = i + 1; k < n; k++) {
                    if (pages[k] == frames[j]) break;
                }

                if (k > farthest) {
                    farthest = k;
                    replace_idx = j;
                }
            }

            frames[replace_idx] = pages[i];

            printf("After inserting %d: ", pages[i]);
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("_ ");
            }
            printf("\n");
        }
    }

    printf("Total Page Faults (Optimal): %d\n", page_faults);
}

void lru(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1, -1};
    int page_faults = 0;
    int used[MAX_FRAMES] = {0, 0, 0, 0};

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                used[j] = i;
                break;
            }
        }

        if (!found) {
            page_faults++;
            int lru_idx = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (used[j] < used[lru_idx]) lru_idx = j;
            }

            frames[lru_idx] = pages[i];
            used[lru_idx] = i;

            printf("After inserting %d: ", pages[i]);
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("_ ");
            }
            printf("\n");
        }
    }

    printf("Total Page Faults (LRU): %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};

    printf("Optimal Page Replacement:\n");
    optimal(pages, MAX_PAGES);

    printf("\nLRU Page Replacement:\n");
    lru(pages, MAX_PAGES);

    return 0;
}
