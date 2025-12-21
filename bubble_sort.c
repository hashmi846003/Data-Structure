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

    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after bubble sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
