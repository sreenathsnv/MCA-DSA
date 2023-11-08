#include<stdio.h>
#include<stdlib.h>

struct cll
{
	int data;
	struct cll *link;
};
struct cll *head;
void create_node(struct cll *node)
{
	int data;
	char c;
	struct cll *new_node;
	printf("\nEnter the data : ");
	scanf("%d",&node->data);
	printf("add more data : ");
	fflush(stdin);
	c = getche();
	
	if(c == 'y')
	{
		if(node->link == head)
		{
		new_node = (struct cll*)malloc(sizeof(struct cll));
		new_node->link = head;
		node->link = new_node;
		create_node(new_node);
		
		}
	}
}
	
void display(struct cll *node)
{
	printf("%d-->",node->data);
	
	if(node->link == head)
	{
		printf("End");
	}
	else
	{
		display(node->link);
	}
}

void main()
{
	head = (struct cll*)malloc(sizeof(struct cll));
	head->link = head;
	create_node(head);
	display(head);
	
}
