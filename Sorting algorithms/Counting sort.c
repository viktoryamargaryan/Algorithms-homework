#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int range) {
    int output[n]; 
    int count[range + 1];
    int i;

    for (i = 0; i <= range; ++i) {
        count[i] = 0;
    }

    for (i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    for (i = 1; i <= range; ++i) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 8; 

    printf("Original array: \n");
    printArray(arr, n);

    countingSort(arr, n, range);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}



 
