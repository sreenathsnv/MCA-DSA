#include<stdio.h>
#include<stdlib.h>

int vertex,column,adjMatrix[100][100];

void create(int src,int dest,int weight)
{
	adjMatrix[src][dest] = weight;
	adjMatrix[dest][src] = weight;
}

void init()
{
	int edge,e,i,j,w;
	printf("Enter number of vertices : ");
	scanf("%d",&vertex);
	printf("Enter number of edges : ");
	scanf("%d",&edge);
	printf("Enter edges(src dest weight) :\n");
	for(e=0;e<edge;e++)
	{
		scanf("%d %d %d",&i,&j,&w);
		create(i,j,w);
	}
}
void display()
{
	int i,j;
	for(i=0;i<vertex;i++)
	{
		for(j=0;j<vertex;j++)
		{
			printf(" %d",adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void BFS(int start)
{
	int* visited = (int*)calloc(vertex,sizeof(int));
	int queue[vertex];
	int front=0,rear=-1,v,i;
	queue[++rear] = start;
	visited[start] = 1;
	while(front<=rear)
	{
		v = queue[front++];
		printf("%d,",v);
		for(i=0;i<vertex;i++)
		{
			if(adjMatrix[v][i] ==1 && !visited[i])
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

void DFS(int start)
{
	int* visited = (int*)calloc(vertex,sizeof(int));
	int stack[vertex],v,i;
	int top =-1;
	stack[++top]= start;
	visited[start]=1;
	
	while(top!= -1)
	{
		v = stack[top--];
		printf("%d,",v);
		for(i=0;i<vertex;i++)
		{
			if(adjMatrix[v][i]== 1 && visited[i] != 1)
			{
				visited[i] = 1;
				stack[++top] = i;
			}
		}
	}
	
}
void main()
{
	int i,j;
	for(i=0;i<vertex;i++)
	{
		for(j=0;j<vertex;j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
	init();
	display();
	BFS(0);	
	DFS(0);
}
