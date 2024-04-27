#include <stdio.h>
#include <stdbool.h>

bool contains(char *str, char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return true;
        }
    }
    return false;
}

int main() {
    char str[100], ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character: ");
    scanf(" %c", &ch); // Notice the space before %c to skip any whitespace

    if (contains(str, ch)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
