#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("ERROR! Please input 4 integers.\n");
        return -1;
    }

    int oddCount = 0, multOf5 = 0, sumOdd = 0, sumAll = 0;
    float avgOdd, avgAll;

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);

        if (num % 2 != 0) {
            oddCount++;
            sumOdd += num;
        }

        if (num % 5 == 0) {
            multOf5++;
        }

        sumAll += num;
    }

    avgOdd = (float)sumOdd / oddCount;
    avgAll = (float)sumAll / 4;

    printf("The number of the odd integers is : %d\n", oddCount);
    printf("The number of integers multiple of 5 is : %d\n", multOf5);
    printf("The average of the odd integers is : %.2f\n", avgOdd);
    printf("The average of all the integers is : %.2f\n", avgAll);

    return 0;
}

