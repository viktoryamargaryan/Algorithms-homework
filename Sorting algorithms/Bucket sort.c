#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int i, j;
    int *buckets[n];
    for (i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int index = arr[i] * n / (max + 1);
        buckets[index][i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                printf("%d ", buckets[i][j]);
            }
        }
    }
}

int main() {
    int arr[] = {29, 13, 82, 37, 52, 49, 71};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nSorted array: \n");
    bucketSort(arr, n);

    return 0;
}

 
