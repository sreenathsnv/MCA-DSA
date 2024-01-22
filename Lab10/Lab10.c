#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    int weight;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int vertices) {
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

struct Node* createNode(int data, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->vertices; ++i) {
        printf("Adjacency list of vertex %d:\n", i);
        struct Node* current = graph->adjacencyList[i];
        while (current) {
            printf("%d(%d) -> ", current->data, current->weight);
            current = current->next;
        }
        printf("NULL\n");
    }
}
// Kruskal's Algorithm
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
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

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph, int edges) {
    int vertices = graph->vertices;
    struct Edge result[vertices];
    int e = 0,i;  
    struct Edge* edgesArray = (struct Edge*)malloc(edges * sizeof(struct Edge));

    printf("Enter the edges (src dest weight):\n");
    for (i = 0; i < edges; ++i) {
        scanf("%d %d %d", &edgesArray[i].src, &edgesArray[i].dest, &edgesArray[i].weight);
    }

    qsort(edgesArray, edges, sizeof(struct Edge), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(vertices * sizeof(struct Subset));

    for (i = 0; i < vertices; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;
    while (e < vertices - 1 && i < edges) {
        struct Edge next_edge = edgesArray[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("\nKruskal's Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i) {
        printf("(%d, %d) - %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
    free(edgesArray);
}

int main() {
    int vertices, edges,i;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest weight):\n");
    for (i = 0; i < edges; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    printGraph(graph);
    kruskalMST(graph, edges);

    return 0;
}
