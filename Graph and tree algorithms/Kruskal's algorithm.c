#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int V, E; 
    Edge* edges; 
} Graph;

typedef struct {
    int parent;
    int rank;
} Subset;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    if (graph->edges == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int compare(const void* a, const void* b) {
    Edge* a_edge = (Edge*)a;
    Edge* b_edge = (Edge*)b;
    return a_edge->weight - b_edge->weight;
}


void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V]; 
    int e = 0; 
    int i = 0; 
  
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare);
    
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    if (subsets == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
 
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    while (e < V - 1 && i < graph->E) {
        
        Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
   
    printf("Following are the edges in the constructed MST:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
}

int main() {
    int V = 4; 
    int E = 5;
    Graph* graph = createGraph(V, E);
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);
    return 0;
}



