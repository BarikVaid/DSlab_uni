#include <stdio.h>

//Access elements of an array
void accessElements() {
    printf("\n--- Access Array Elements ---\n");
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Element at index 2: %d\n", arr[2]);
}
