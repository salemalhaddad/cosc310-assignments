#include <stdio.h>

int main() {
    int numbers[10];
    int max, min;

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    max = min = numbers[0];

    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
