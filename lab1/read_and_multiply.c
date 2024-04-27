#include <stdio.h>

int multi(int x, int y, int j) {
    return x * y * j;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <x> <y> <z> <i> <j>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);
    int i = atoi(argv[4]);
    int j;

    printf("Enter an integer j: ");
    scanf("%d", &j);

    int result = multi(x, y, j);

    printf("Multiplication result: %d\n", result);

    return 0;
}
