#include <stdio.h>

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int key = 40, low = 0, high = 4;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key) {
            printf("Found at index %d\n", mid);
            return 0;
        } else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("Not Found\n");
    return 0;
}
