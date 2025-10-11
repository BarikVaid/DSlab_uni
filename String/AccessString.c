#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Characters in the string are:\n");
    for(i = 0; str[i] != '\0'; i++) {
        printf("str[%d] = %c\n", i, str[i]);
    }

    return 0;
}
//cse78