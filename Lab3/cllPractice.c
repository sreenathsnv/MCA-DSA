#include<stdio.h>
#include<stdlib.h>

struct cll 
{
	int data;
	struct cll* link;
};

struct cll *head;

void createNode(struct cll *ptr)
{
	char opt;
	printf("\nEnter the data :");
	scanf("%d",&ptr->data);
	printf("\n add more? : ");
	
	opt = getche();
	if(opt =='y')
	{
		ptr->link = (struct cll*)malloc(sizeof(struct cll));
		createNode(ptr->link);
	}
	else
	{
		ptr->link = head;
	}
	
}

void display(struct cll *ptr)
{
	printf("%d-->",ptr->data);
	if(ptr->link == head)
	{
		printf("End");
	}
	else
	{
		display(ptr->link);
	}
}


void main()
{
	head = (struct cll*)malloc(sizeof(struct cll));
	createNode(head);
	display(head);
}
