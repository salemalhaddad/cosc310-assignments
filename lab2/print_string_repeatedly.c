#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        printf("%s\n", str + i);
    }

    return 0;
}
