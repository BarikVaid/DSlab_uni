#include <stdio.h>

int main() {
    int arr[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n > 0) {
        n--;  
    }

    printf("Array after deleting from end: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
