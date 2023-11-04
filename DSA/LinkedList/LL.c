#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void create_node(struct node *ptr)
{
	
	char c;
	printf("\nEnter the data : ");
	scanf("%d",&ptr->data);
	printf("\nYou want to add more data : ");
	c = getche();
	if(c == 'y')
	{
		ptr->link = (struct node*)malloc(sizeof(struct node));
		create_node(ptr->link);
		
	}
	else
	{
		ptr->link = NULL;
	}
	
}

void traversal(struct node *ptr)
{
	printf("(%d)->",ptr->data);
	if(ptr->link != NULL)
	{
		traversal(ptr->link);
	}
	else
	{
		printf("End\n");
	}
	
	
}

struct node* insert_begin(struct node *ptr)
{
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&new_node->data);
	if(ptr->data != NULL)
	{
		new_node->link = ptr;
	}
	else
	{
		new_node->link = NULL;  
	}
	return new_node;
}


void insert_end(struct node *ptr)
{
	int data;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&data);
	
	if(ptr->data != NULL)
	{
		new_node->data = data;
		new_node->link = NULL;
		
		while(ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = new_node;
	}
	else
	{
		ptr->data = data;
		ptr->link =NULL;
	}
	
	
}

void main()
{
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = NULL;
	
	create_node(head);
	traversal(head);
	head = insert_begin(head);
	traversal(head);
	insert_end(head);
	traversal(head);
}

