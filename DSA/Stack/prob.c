#include<stdio.h>
#include<stdlib.h>

struct ll
{
	char data;
	struct ll *link;	
};

struct ll *top = NULL;

void push(struct ll *ptr)
{
	char opt;
	struct ll *newNode = (struct ll *)malloc(sizeof(struct ll));
	printf("\nEnter the char : ");
	newNode->data = getche();
	if(ptr == NULL)
	{
		newNode->link = NULL;
		top = newNode;
	}
	else
	{
		newNode->link = top;
		top = newNode;
	}
	printf("\nadd More (y/n) : ");
	opt = getche();
	if(opt == 'y')
	{
		push(newNode);
	}
	else
	{
		printf("\nstack created...");
	}
}

void display(struct ll *ptr)
{
	if(ptr != NULL)
	{
		
		display(ptr->link);
		printf("%c",ptr->data);
	}
	else
		printf("\n");
	
}

void pop(struct ll *ptr)
{
	char opt;
	if(ptr == NULL)
	{
		printf("\nStack is empty...");
	}
	else
	{
		top = ptr->link;
	}
	printf("\npop More? (y/n) : ");
	opt = getche();
	if(opt == 'y')
	{
		pop(top);
	}
	display(top);
	
	
}



void main()

{
	
//	printf("Creating Stack...\n");
//	push(top);
//	display(top);
//	pop(top); 
//	
	char opt;
	do
	{
		opt = getche();
		if(opt == "\b")
		{
			printf("backspace");
			}	
	}while(opt != "\n");	
}
