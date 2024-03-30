#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct MinHeapNode {
    Node *data;
    struct MinHeapNode *next;
} MinHeapNode;

typedef struct MinHeap {
    MinHeapNode *head;
} MinHeap;

Node* createNode(char data, int freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

MinHeapNode* createMinHeapNode(Node* data) {
    MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    if (minHeap == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    minHeap->head = NULL;
    return minHeap;
}

void swapMinHeapNodes(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(MinHeap* minHeap, Node* data) {
    MinHeapNode* newNode = createMinHeapNode(data);
    if (minHeap->head == NULL) {
        minHeap->head = newNode;
    } else {
        newNode->next = minHeap->head;
        minHeap->head = newNode;
    }
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap();
    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, createNode(data[i], freq[i]));
    }
    return minHeap;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (minHeap->head->next != NULL) {
        MinHeapNode *left = minHeap->head, *right = minHeap->head->next;
        minHeap->head = minHeap->head->next->next;
        Node* newNode = createNode('$', left->data->freq + right->data->freq);
        newNode->left = left->data;
        newNode->right = right->data;
        free(left);
        free(right);
        insertMinHeap(minHeap, newNode);
    }
    Node* huffmanTreeRoot = minHeap->head->data;
    free(minHeap);
    return huffmanTreeRoot;
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffmanEncoding(char data[], int freq[], int size) {
    Node* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printf("Huffman codes:\n");
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffmanEncoding(data, freq, size);
    return 0;
}


