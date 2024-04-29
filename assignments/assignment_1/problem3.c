#include <stdio.h>
#include <stdbool.h>

int main() {
    int N, num, count = 0;
    bool hasConsecutiveOdd = false;
    int prev1, prev2;

    printf("Please enter N, the number of integers in the list: ");
    scanf("%d", &N);

    if (N <= 3 || N >= 20) {
        printf("Number of integers should be greater than 3 and less than 20.\n");
        return -1;
    }

    printf("Please enter the %d integers:\n", N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num % 2 != 0) {
            count++;

            if (count == 3) {
                hasConsecutiveOdd = true;
                break;
            }
        } else {
            count = 0;
        }
    }

    if (hasConsecutiveOdd) {
        printf("Three consecutive odd integers? YES\n");
    } else {
        printf("Three consecutive odd integers? NO\n");
    }

    return 0;
}

