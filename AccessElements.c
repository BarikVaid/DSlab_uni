#include <stdio.h>

int main() {
    int arr[50], n, i, pos;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray elements: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("\nEnter position to access (1 to %d): ", n);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return 0;
    }
    
    printf("Element at position %d: %d\n", pos, arr[pos-1]);
    
    return 0;
}
