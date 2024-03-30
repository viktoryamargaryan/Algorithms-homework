#include <stdio.h>

void shakerSort(int arr[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;
    int i;

    while (swapped) {
        swapped = 0;
        
        for (i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        end--;

        for (i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        start++;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {68, 34, 45, 10, 2, 51, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    shakerSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
