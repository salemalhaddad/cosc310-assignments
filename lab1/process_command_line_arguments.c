#include <stdio.h>
#include <stdlib.h>

void printIntegers(int a, int b) {
    printf("Arguments: %d, %d\n", a, b);
}

void printSum(int a, int b) {
    int sum = a + b;
    printf("Sum of arguments: %d\n", sum);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer1> <integer2>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printIntegers(a, b);
    printSum(a, b);

    return 0;
}
