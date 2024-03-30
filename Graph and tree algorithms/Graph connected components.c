#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data; 
    int parent; 
} Element;

Element* createSet(int n) {
    Element* set = (Element*)malloc(n * sizeof(Element));
    if (set == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        set[i].data = i;
        set[i].parent = -1; 
    }
    return set;
}

int find(Element* set, int i) {
    while (set[i].parent != -1) {
        i = set[i].parent;
    }
    return i;
}

void unionSets(Element* set, int x, int y) {
    int xRoot = find(set, x);
    int yRoot = find(set, y);
    if (xRoot != yRoot) {
        set[xRoot].parent = yRoot; 
    }
}

int areConnected(Element* set, int x, int y) {
    return find(set, x) == find(set, y);
}

int main() {
    int n = 5; 
    Element* set = createSet(n);

    unionSets(set, 0, 1);
    unionSets(set, 2, 3);
    unionSets(set, 0, 4);

    printf("0 and 3 are connected: %s\n", areConnected(set, 0, 3) ? "Yes" : "No");
    printf("1 and 4 are connected: %s\n", areConnected(set, 1, 4) ? "Yes" : "No");
    printf("2 and 3 are connected: %s\n", areConnected(set, 2, 3) ? "Yes" : "No");

    free(set);
    return 0;
}




