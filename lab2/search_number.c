#include <stdio.h>
#include <stdbool.h>

bool search(int A[], int num, int size) {
    for (int i = 0; i < size; i++) {
        if (A[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    int size = 10; // Assuming array size is 10
    int array[10];

    printf("Enter 10 integers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int number;
    printf("Enter a number to search for: ");
    scanf("%d", &number);

    if (search(array, number, size)) {
        printf("Number found in the array.\n");
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}
