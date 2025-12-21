#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements (sorted)\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element\n");
    scanf("%d", &target);

    int low = 0, high = size - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            printf("%d found at position %d\n", target, mid + 1);
            found = 1;
            break;
        } else if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}
