#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements (1 < n < 10): ");
    scanf("%d", &n);

    if (n < 2 || n >= 10) {
        printf("Invalid input for n. Please enter a number between 2 and 9.\n");
        return 1;
    }

    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    double average = (double)sum / n;
    printf("Average of %d numbers is: %.2lf\n", n, average);

    return 0;
}
