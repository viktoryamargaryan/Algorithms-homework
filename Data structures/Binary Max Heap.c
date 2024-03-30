#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *items;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->items = (int*)malloc(capacity * sizeof(int));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    return maxHeap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void insert(MaxHeap* maxHeap, int value) {
    if (maxHeap->size == maxHeap->capacity) {
        printf("Heap is full\n");
        return;
    }
    maxHeap->items[maxHeap->size++] = value;
    int i = maxHeap->size - 1;
    while (i != 0 && maxHeap->items[i] > maxHeap->items[parent(i)]) {
        swap(&maxHeap->items[i], &maxHeap->items[parent(i)]);
        i = parent(i);
    }
}

void heapify(MaxHeap* maxHeap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if (left < maxHeap->size && maxHeap->items[left] > maxHeap->items[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->items[right] > maxHeap->items[largest])
        largest = right;
    if (largest != i) {
        swap(&maxHeap->items[i], &maxHeap->items[largest]);
        heapify(maxHeap, largest);
    }
}

int extractMax(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return -1;
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->items[0];
    }
    int root = maxHeap->items[0];
    maxHeap->items[0] = maxHeap->items[maxHeap->size - 1];
    maxHeap->size--;
    heapify(maxHeap, 0);
    return root;
}

int peek(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return -1;
    return maxHeap->items[0];
}

void increaseKey(MaxHeap* maxHeap, int i, int newValue) {
    if (newValue < maxHeap->items[i]) {
        printf("New value is smaller than the current value\n");
        return;
    }
    maxHeap->items[i] = newValue;
    while (i != 0 && maxHeap->items[i] > maxHeap->items[parent(i)]) {
        swap(&maxHeap->items[i], &maxHeap->items[parent(i)]);
        i = parent(i);
    }
}

int main() {
    MaxHeap* maxHeap = createMaxHeap(MAX_SIZE);

    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    insert(maxHeap, 25);

    printf("Maximum element (peek): %d\n", peek(maxHeap));

    printf("Extracted max element: %d\n", extractMax(maxHeap));

    increaseKey(maxHeap, 2, 35);

    printf("Maximum element after increaseKey: %d\n", peek(maxHeap));

    free(maxHeap->items);
    free(maxHeap);

    return 0;
}

