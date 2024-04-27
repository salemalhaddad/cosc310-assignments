#include <stdio.h>

int main() {
    char str[100];
    int number;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("String: %s", str);
    printf("Integer: %d\n", number);
    return 0;
}
