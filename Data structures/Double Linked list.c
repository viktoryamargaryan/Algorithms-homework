#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = prev;
        }
    }
    free(current);
}

Node* search(Node* head, int data) {
    Node* current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    printf("Doubly linked list: ");
    printList(head);

    deleteNode(&head, 20);

    printf("After deleting 20: ");
    printList(head);

    int searchData = 10;
    Node* searchResult = search(head, searchData);
    if (searchResult != NULL) {
        printf("%d found in the list\n", searchData);
    } else {
        printf("%d not found in the list\n", searchData);
    }

    freeList(head);

    return 0;
}


