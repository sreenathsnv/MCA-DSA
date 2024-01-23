
//circular ll
#include<stdio.h>
#include<stdlib.h>


typedef struct cll
{
	int data;
	struct cll* link;
}node;

node* head = NULL;

node* createNode(node* temp)
{
	char y;
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	printf("Add more : ");
	y = getche();
	if(y =='y')
	{
		temp->link = (node*)malloc(sizeof(node));
		temp->link = createNode(temp->link);
	}
	else
	{
		temp->link = head;
	}
	return temp;
}

void display(node* ptr)
{
	while(ptr->link!= head)
	{
		printf(" %d->",ptr->data);
		ptr = ptr->link;
	}
}

void main()
{
	head = (node*)malloc(sizeof(node));
	createNode(head);
	display(head);
}

