#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++);  
    str[i - 1] = '\0';  

    printf("After deleting last character: %s\n", str);
    return 0;
}
//cse78