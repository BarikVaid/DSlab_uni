#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char ch;
    int i;

    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a character to add at the beginning: ");
    scanf(" %c", &ch);

    int len = strlen(str);

    
    for(i = len; i >= 0; i--) {
        str[i + 1] = str[i];
    }

    str[0] = ch;  

    printf("New string: %s\n", str);
    return 0;
}
//cse78