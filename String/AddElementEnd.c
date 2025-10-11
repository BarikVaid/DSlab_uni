#include <stdio.h>

int main() {
    char str[100];
    char ch;
    int i;

    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a character to add at the end: ");
    scanf(" %c", &ch);

    for(i = 0; str[i] != '\0'; i++);  

    str[i] = ch;      
    str[i + 1] = '\0'; 

    printf("New string: %s\n", str);
    return 0;
}
//cse78