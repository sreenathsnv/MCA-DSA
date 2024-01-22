#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int src, dest, weight;
} edge;

typedef struct graph {
    int V;
    int E;
    edge *edgeList;
} graph;

graph *createGraph(int V, int E) {
    graph *graph = (graph*)malloc(sizeof(graph));
    graph->V = V;
    graph->E = E;
    graph->edgeList = (edge *)malloc(E * sizeof(edge));
    return graph;
}

int compare(const void *a, const void *b) {
    edge *edge1 = (edge *)a;
    edge *edge2 = (edge *)b;
    return edge1->weight > edge2->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal(graph *graph) {
    int V = graph->V;
    int E = graph->E;
    edge result[V];
    int e = 0;
    int i = 0;
    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    qsort(graph->edgeList, E, sizeof(edge), compare);

    while (e < V - 1 && i < E) {
        edge next_edge = graph->edgeList[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(parent, rank, x, y);
        }
    }

    printf("Minimum Spanning Tree using Kruskal's Algorithm:\n");
    for (int i = 0; i < V - 1; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

void prim(graph *graph) {
    int V = graph->V;
    int E = graph->E;
    int visited[V];
    int parent[V];
    int key[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(V, visited, key);
        visited[u] = 1;

        for (int v = 0; v < E; v++) {
            int src = graph->edgeList[v].src;
            int dest = graph->edgeList[v].dest;
            int weight = graph->edgeList[v].weight;

            if (visited[src] == 0 && visited[dest] == 0 && weight < key[dest]) {
                parent[dest] = src;
                key[dest] = weight;
            }
        }
    }

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    for (int i = 1; i < V; i++) {
        printf("%d -- %d == %d\n", parent[i], i, key[i]);
    }
}

int minKey(int V, int visited[], int key[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    graph *graph = createGraph(V, E);

    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edgeList[i].src, &graph->edgeList[i].dest,
              &graph->edgeList[i].weight);
    }

    kruskal(graph);
    prim(graph);

    return 0;
}