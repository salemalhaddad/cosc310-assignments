#include <stdio.h>

int find_max(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main() {
    int x, y, z;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &x, &y, &z);

    int max = find_max(x, y, z);

    printf("The maximum of %d, %d, and %d is %d\n", x, y, z, max);

    return 0;
}
