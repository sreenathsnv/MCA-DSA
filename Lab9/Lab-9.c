#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Graph {
    int numVertices;
    Node* adjacencyList[MAX_VERTICES];
} Graph;


typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;


Node* createNode(int data);
Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest);
void BFT(Graph* graph, int startVertex);
void DFTUtil(Graph* graph, int vertex, bool* visited);
void DFT(Graph* graph, int startVertex);
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
bool searchBFT(Graph* graph, int startVertex, int targetVertex);
bool searchDFT(Graph* graph, int startVertex, int targetVertex);
bool searchDFTUtil(Graph* graph, int vertex, int targetVertex, bool* visited);


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Graph* createGraph(int numVertices) {
	int i;
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (i = 0; i < numVertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}


void addEdge(Graph* graph, int src, int dest) {

    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;


    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}


void BFT(Graph* graph, int startVertex) {
	int i;
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = MAX_VERTICES;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));

    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (i = 0; i < graph->numVertices; ++i)
        visited[i] = false;

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjacencyList[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(queue->array);
    free(queue);
    free(visited);
}


void DFTUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* temp = graph->adjacencyList[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            DFTUtil(graph, adjVertex, visited);
        temp = temp->next;
    }
}

void DFT(Graph* graph, int startVertex) {
	
	int i;
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (i = 0; i < graph->numVertices; ++i)
        visited[i] = false;

    DFTUtil(graph, startVertex, visited);

    free(visited);
}


bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}


void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity)
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}


int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return item;
}


bool searchBFT(Graph* graph, int startVertex, int targetVertex) {
	int i;
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = MAX_VERTICES;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));

    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (i = 0; i < graph->numVertices; ++i)
        visited[i] = false;

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        if (currentVertex == targetVertex) {
            
            free(queue->array);
            free(queue);
            free(visited);
            return true;
        }

        Node* temp = graph->adjacencyList[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }


    free(queue->array);
    free(queue);
    free(visited);
    return false;
}


bool searchDFT(Graph* graph, int startVertex, int targetVertex) {
	int i;
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (i = 0; i < graph->numVertices; ++i)
        visited[i] = false;

    bool result = searchDFTUtil(graph, startVertex, targetVertex, visited);

    free(visited);
    return result;
}


bool searchDFTUtil(Graph* graph, int vertex, int targetVertex, bool* visited) {
    visited[vertex] = true;

    if (vertex == targetVertex) {

        return true;
    }

    Node* temp = graph->adjacencyList[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            if (searchDFTUtil(graph, adjVertex, targetVertex, visited))
                return true;
        }
        temp = temp->next;
    }

    return false;
}

int main() {
    int numVertices, numEdges, startVertex, choice, targetVertex,i;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex pairs):\n");
    for (i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Breadth-First Traversal (BFT)\n");
        printf("2. Depth-First Traversal (DFT)\n");
        printf("3. Search using Breadth-First Traversal (BFT)\n");
        printf("4. Search using Depth-First Traversal (DFT)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the starting vertex for BFT: ");
                scanf("%d", &startVertex);
                printf("Breadth-First Traversal (BFT): ");
                BFT(graph, startVertex);
                break;

            case 2:
                printf("Enter the starting vertex for DFT: ");
                scanf("%d", &startVertex);
                printf("Depth-First Traversal (DFT): ");
                DFT(graph, startVertex);
                break;

            case 3:
                printf("Enter the target vertex for search using BFT: ");
                scanf("%d", &targetVertex);
                if (searchBFT(graph, startVertex, targetVertex))
                    printf("Vertex %d found using Breadth-First Traversal.\n", targetVertex);
                else
                    printf("Vertex %d not found using Breadth-First Traversal.\n", targetVertex);
                break;

            case 4:
                printf("Enter the target vertex for search using DFT: ");
                scanf("%d", &targetVertex);
                if (searchDFT(graph, startVertex, targetVertex))
                    printf("Vertex %d found using Depth-First Traversal.\n", targetVertex);
                else
                    printf("Vertex %d not found using Depth-First Traversal.\n", targetVertex);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

