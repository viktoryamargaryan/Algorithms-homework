#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initialize(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(CircularQueue *queue) {
    return queue->front == -1;
}

int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = item;
}

int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

int peek(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Front element: %d\n", peek(&queue));

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    printf("Is queue empty? %s\n", isEmpty(&queue) ? "Yes" : "No");

    return 0;
}

