#include <stdio.h>

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if (arr[pos] == key) {
            return pos;
        }

        else if (arr[pos] < key) {
            low = pos + 1;
        }
        
        else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {12, 23, 34, 45, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int result = interpolationSearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
