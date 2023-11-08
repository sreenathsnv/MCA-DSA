#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};


struct node *head = NULL;





void create_node(struct node *ptr)
{
	
	char c;
	if(ptr != NULL)
	{
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
	else
	{
		head = (struct node*)malloc(sizeof(struct node));
		create_node(head);
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
	if(ptr != NULL)
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
	
	if(ptr != NULL)
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

int length(struct node *ptr)
{
	int count=1;
	while(ptr->link != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	return count;
}

void insert(struct node *ptr)
{
	int pos,count=1,len = length(head);
	struct node *newnode = (struct node*)malloc(sizeof(struct node)),*temp = ptr->link;
	printf("In which position u want to add elements(0-n) : ");
	scanf("%d",&pos);
	printf("Enter the data : ");
	scanf("%d",&newnode->data);
	if(pos>0 && pos<len-1)
	{
		while(count<pos)
		{
			ptr = ptr->link;
			temp = temp->link;
			count++;
		}
		newnode->link = temp;
		ptr->link = newnode;
		
	}
	else if(pos ==0)
		insert_begin(ptr);
	else if(pos == len)
	{
		insert_end(ptr);
	}
	else
	{
		printf("Invalid input!!");
	}
	
	
	
}



void delete_end(struct node *ptr){
	
	int pos;
	struct node *temp;
	
	temp = ptr->link;
	while(temp->link !=NULL)
	{
		temp= temp->link;
		ptr = ptr->link;
	}
	ptr->link = NULL;
	free(temp);
	
}
void delete_begin(struct node *ptr)
{
	head = ptr->link;
	free(ptr);
}
void main()

{
	
	int opt;
	do{
		
	printf("\n\n1.Create a node\n2.print List\n3.insert at beginning\n4.insert at end\n5.insert at position\ndelete from beginning\n\
	6.delete from end\nChoose from above : ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			create_node(head);
			break;
		case 2:
			traversal(head);
			break;
		case 3:
			head = insert_begin(head);
			break;
		case 4:
			insert_end(head);
			break;
		case 5:
			insert(head);
			break;
		case 6:
			delete_end(head);
			traversal(head);
			break;
		case 7:
			delete_begin(head);
			traversal(head);
			break;
		
		}
	}while(opt <10);
//	create_node(head);
//	traversal(head);
//	head = insert_begin(head);
//	traversal(head);
//	insert_end(head);
//	traversal(head);
//	insert(head);
//	traversal(head);
//	delete_end(head);
//	traversal(head);
}

