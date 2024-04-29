#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isArmstrong(int x) {
    int originalNum, remainder, result = 0, n = 0;

    originalNum = x;

    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = x;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    return result == x;
}

int main() {
    int num;
    
    printf("Please enter a positive 3-digit integer: ");
    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("The number should be a positive 3-digit integer\n");
        return -1;
    }

    if (num < 0) {
        printf("The number should not be negative\n");
        return -1;
    }

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number\n", num);
    } else {
        printf("%d is not an Armstrong number\n", num);
    }

    return 0;
}

