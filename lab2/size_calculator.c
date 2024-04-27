#include <stdio.h>
#include <string.h>

int main(){
    char letters[10];

    if(fgets(letters, sizeof(letters), stdin) == NULL)
        return 1;

    if (letters[strlen(letters)-1] != '\n')
        printf("Input is too long\n");

    printf("str is %lu", strlen(letters));
}
