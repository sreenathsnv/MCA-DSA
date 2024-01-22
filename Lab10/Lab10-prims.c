#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100


int minKey(int key[], int mstSet[], int V) {
    int v,min = INT_MAX, min_index;

    for (v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}


void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
	int i ;
    printf("Edge   Weight\n");
    for (i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
	int i ,count,v;
    int parent[MAX_VERTICES]; 
    int key[MAX_VERTICES];    
    int mstSet[MAX_VERTICES]; 

  
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

  
    key[0] = 0;    
    parent[0] = -1;

    
    for (count = 0; count < V - 1; count++) {
    
        int u = minKey(key, mstSet, V);

        
        mstSet[u] = 1;

        
        for ( v = 0; v < V; v++) {
        
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    
    printMST(parent, graph, V);
}

int main() {
    int V,i,j;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);

    if (V > MAX_VERTICES) {
        printf("Number of vertices exceeds the maximum limit.\n");
        return 1;
    }

    
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    
    primMST(graph, V);

    return 0;
}

