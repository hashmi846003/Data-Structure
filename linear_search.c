#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int target;
    printf("\nEnter the target element\n");
    scanf("%d", &target);

    int found = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("%d is found at position %d\n", target, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}
