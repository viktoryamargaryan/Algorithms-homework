#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int key) {

    if (arr[0] == key) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= key) {
        i *= 2;
    }

    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, key);
}

int main() {
    int arr[] = {1, 3, 5, 18, 36};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 14;
    int result = exponentialSearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
