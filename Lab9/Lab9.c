#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employeeNode {
    int id;
    char *name;
    int age;
    char *role;
    int experience;
    int salary;
};

struct graphNode {
    struct employeeNode data;
    struct graphNode *next;
};

struct Graph {
    int numNodes;
    struct graphNode *adjacencyList;
};

struct employeeNode *createEmployeeNode(int id, const char *name, int age, const char *role, int experience, int salary) {
    struct employeeNode *newNode = (struct employeeNode *)malloc(sizeof(struct employeeNode));
    newNode->id = id;
    newNode->name = strdup(name);
    newNode->age = age;
    newNode->role = strdup(role);
    newNode->experience = experience;
    newNode->salary = salary;
    return newNode;
}

struct graphNode *createGraphNode(struct employeeNode *data) {
    struct graphNode *newNode = (struct graphNode *)malloc(sizeof(struct graphNode));
    newNode->data = *data;
    newNode->next = NULL;
    return newNode;
}

struct Graph createGraph(int numNodes) {
    int i;
    struct Graph graph;
    graph.numNodes = numNodes;
    graph.adjacencyList = (struct graphNode *)malloc(numNodes * sizeof(struct graphNode));

    for (i = 0; i < numNodes; ++i) {
        graph.adjacencyList[i].next = NULL;
    }

    return graph;
}

void addEdge(struct Graph *graph, struct employeeNode *src, struct employeeNode *dest) {
    int srcIndex, destIndex;
    struct graphNode *srcNode, *destNode, *temp;

    srcIndex = src->id - 1;
    destIndex = dest->id - 1;

    srcNode = &graph->adjacencyList[srcIndex];
    destNode = &graph->adjacencyList[destIndex];

    temp = srcNode->next;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    if (temp == NULL) {
        srcNode->next = createGraphNode(src);
        temp = srcNode->next;
    }

    temp->next = createGraphNode(dest);
}



void printGraph(struct Graph *graph) {
    int i;
    struct graphNode *current;
    for (i = 0; i < graph->numNodes; ++i) {
        current = graph->adjacencyList[i].next;
        printf("Node %d: ", i + 1);
        while (current != NULL) {
            printf("(%d) %s -> ", current->data.id, current->data.name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void dfsUtil(struct Graph *graph, int v, int *visited) {
    visited[v] = 1;

    struct graphNode *current = graph->adjacencyList[v].next;
    if (current == NULL) {
        return;
    }

    printf("(%d) %s -> ", graph->adjacencyList[v].data.id, graph->adjacencyList[v].data.name);

    while (current != NULL) {
        int neighbor = current->data.id - 1;
        if (!visited[neighbor]) {
            dfsUtil(graph, neighbor, visited);
        }
        current = current->next;
    }
}
void dfs(struct Graph *graph) {
    int i;
    int *visited = (int *)malloc(graph->numNodes * sizeof(int));
    for (i = 0; i < graph->numNodes; ++i) {
        visited[i] = 0;
    }

    printf("Depth-First Traversal:\n");
    for (i = 0; i < graph->numNodes; ++i) {
        if (!visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }

    printf("NULL\n");

    free(visited);
}



void bfsUtil(struct Graph *graph, int *visited, int current, int level) {
    if (level == 0) {
        printf("(%d) %s -> ", graph->adjacencyList[current].data.id, graph->adjacencyList[current].data.name);
        visited[current] = 1;
        return;
    }

    struct graphNode *temp = graph->adjacencyList[current].next;
    if (temp == NULL) {
        return;
    }

    while (temp != NULL) {
        int neighbor = temp->data.id - 1;
        if (!visited[neighbor]) {
            bfsUtil(graph, visited, neighbor, level - 1);
        }
        temp = temp->next;
    }
}

void bfs(struct Graph *graph) {
    int i, level;
    int *visited = (int *)malloc(graph->numNodes * sizeof(int));
    for (i = 0; i < graph->numNodes; ++i) {
        visited[i] = 0;
    }

    printf("Breadth-First Traversal:\n");

    for (level = 0; level < graph->numNodes; ++level) {
        for (i = 0; i < graph->numNodes; ++i) {
            if (!visited[i]) {
                bfsUtil(graph, visited, i, level);
            }
        }
    }

    printf("NULL\n");

   
}

int main() {
    int numNodes;
    int i, id, age, experience, salary;
    char name[20], role[20];
    struct Graph myGraph;
    struct employeeNode *node;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    myGraph = createGraph(numNodes);

    for (i = 0; i < numNodes; ++i) {
    printf("Enter details for Node %d:\n", i + 1);
    printf("ID: ");
    scanf("%d", &id);
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Role: ");
        scanf("%s", role);
        printf("Experience: ");
        scanf("%d", &experience);
        printf("Salary: ");
        scanf("%d", &salary);

        node = createEmployeeNode(id, name, age, role, experience, salary);
        addEdge(&myGraph, node, node);
    }

    printf("\nGraph details:\n");
    printGraph(&myGraph);

    printf("\nDepth-First Traversal:\n");
    dfs(&myGraph);

    printf("\nBreadth-First Traversal:\n");
    bfs(&myGraph);

    return 0;
}

