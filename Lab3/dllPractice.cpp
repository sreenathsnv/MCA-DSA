#include<stdio.h>
#include<stdlib.h>

struct dll
{
	struct dll *prev;
	int data;
	struct dll *next;
};

struct dll *head;

void createNode(struct dll* ptr)
{
	char c;
	scanf("%d",&ptr->data);
	c = getche();
	if(c == 'y')
	{
		ptr->next = (struct dll *)malloc(sizeof(struct dll));
		ptr->next->prev = ptr;
		createNode(ptr->next);
	}
	else
	{
		ptr->next = NULL;
	}
}

void display(struct dll *ptr)
{
	printf("%d-->",ptr->data);
	if(ptr->next == NULL)
		printf("End");
	else
		display(ptr->next);
}


void main()
{
	head = (struct dll *)malloc(sizeof(struct dll));
	head->prev = NULL;
}
