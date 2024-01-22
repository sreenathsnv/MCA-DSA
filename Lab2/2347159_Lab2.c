

#include<stdio.h>
#include<stdlib.h>
#include "Employee.h"
#include<string.h>

// find length

int len(struct employeeList *ptr)
{
	int count =1;
	while(ptr->link != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	return count;
}

// create a new list function
void create(struct employeeList *ptr)
{
	struct employeeList *newnode;
	char c;
	ptr->data = (struct employeeNode*)malloc(sizeof(struct employeeNode));
	printf("\n\nEnter the employee ID : ");
	scanf("%d",&ptr->data->id);
	fflush(stdin);
	printf("Enter the employee Name : ");
	gets(ptr->data->name);
	printf("Enter the employee Age : ");
	scanf("%d",&ptr->data->age);
	fflush(stdin);
	printf("Enter the employee Role : ");
	gets(ptr->data->role);
	printf("Enter the employee Experience : ");
	scanf("%d",&ptr->data->experience);
	printf("Enter the employee Salary : ");
	scanf("%d",&ptr->data->salary);
	
	printf("Add more data : ");
	c = getche();
	
	if(c == 'y')
	{
		newnode = (struct employeeList*)malloc(sizeof(struct employeeList));
		ptr->link = newnode;
		create(newnode);
		
	}
	else
	{
		ptr->link = NULL;
	}
}

// insert functions

struct employeeList* insert_at_begin(struct employeeList *ptr )
{
	
	struct employeeList *newnode = (struct employeeList*)malloc(sizeof(struct employeeList));
	newnode->data = (struct employeeNode*)malloc(sizeof(struct employeeNode));
	printf("Enter the employee ID : ");
	scanf("%d",&newnode->data->id);
	fflush(stdin);
	printf("Enter the employee Name : ");
	gets(newnode->data->name);
	printf("Enter the employee Age : ");
	scanf("%d",&newnode->data->age);
	fflush(stdin);
	printf("Enter the employee Role : ");
	gets(newnode->data->role);
	printf("Enter the employee Experience : ");
	scanf("%d",&newnode->data->experience);
	printf("Enter the employee Salary : ");
	scanf("%d",&newnode->data->salary);
	
	newnode->link = ptr;
	
	return newnode;
	
	
}


void insert_at_end(struct employeeList *ptr)
{
	struct employeeList *newnode = (struct employeeList*)malloc(sizeof(struct employeeList));
	newnode->data = (struct employeeNode*)malloc(sizeof(struct employeeNode));
	printf("Enter the employee ID : ");
	scanf("%d",&newnode->data->id);
	printf("Enter the employee Name : ");
	fflush(stdin);
	gets(newnode->data->name);
	printf("Enter the employee Age : ");
	scanf("%d",&newnode->data->age);
	printf("Enter the employee Role : ");
	fflush(stdin);
	gets(newnode->data->role);
	printf("Enter the employee Experience : ");
	scanf("%d",&newnode->data->experience);
	printf("Enter the employee Salary : ");
	scanf("%d",&newnode->data->salary);
	
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	newnode->link = NULL;
	ptr->link = newnode;
}

void insert(struct employeeList *ptr){
	struct employeeList *newnode = (struct employeeList*)malloc(sizeof(struct employeeList));
	int pos,i=0;
	newnode->data = (struct employeeNode*)malloc(sizeof(struct employeeNode));
	printf("In which position you want to add : ");
	scanf("%d",&pos);
	if(0<pos && (pos<len(ptr)-1))
	{
		
		printf("Enter the employee ID : ");
		scanf("%d",&newnode->data->id);
		fflush(stdin);
		printf("Enter the employee Name : ");
		gets(newnode->data->name);
		printf("Enter the employee Age : ");
		scanf("%d",&newnode->data->age);
		printf("Enter the employee Role : ");
		fflush(stdin);
		gets(newnode->data->role);
		printf("Enter the employee Experience : ");
		scanf("%d",&newnode->data->experience);
		printf("Enter the employee Salary : ");
		scanf("%d",&newnode->data->salary);
		while(i<pos)
		{
			ptr = ptr->link;
			printf("%d",ptr->data->id);
			++i;
		}
		newnode->link = ptr->link;
		ptr->link = newnode;
	}
	else
	{
		printf("Invalid Input!!\n");
	}
	
}

//delete functions


void delete_begin(struct employeeList *ptr)
{
	
	head = ptr->link;
	free(ptr);
		
}

void delete_end(struct employeeList *ptr)
{
	struct employeeList *temp = ptr->link;
	while(temp->link != NULL)
	{
		ptr = ptr->link;
		temp = temp->link;
	}
	ptr->link = NULL;
	free(temp);
}
void delete_at(struct employeeList *ptr)
{
	int id;
	struct employeeList *temp = ptr->link;
	if(len(ptr)>2)
	{
		printf("\nEnter the ID of the employee you want to remove : ");
	scanf("%d",&id);
	while(temp->data->id != id)
	{
		ptr = ptr->link;
		temp = temp->link;
	}
	ptr->link = temp->link;
	free(temp);
	}
	else
	{
		printf("Can\'t perform the operation! length<2");
	}
}

//serach and update functions

void search_by_id(struct employeeList *ptr)
{
	int id,flag=0;
	printf("\nEnter the ID of the employee you want to search : ");
	scanf("%d",&id);
	while(ptr->data->id != id)
	{
		if(ptr->link == NULL)
		{
			printf("ID not found!!");
			flag = 1;
			break;
		}
		
		else
		{
			ptr = ptr->link;
		}
	}
	if(flag != 1)
	{
	printf("\n==========================\n");
	printf("\tEmployee ID : %d\n",ptr->data->id);
	printf("\tEmployee Name : %s\n",ptr->data->name);
	printf("\tEmployee Age : %d\n",ptr->data->age);
	printf("\tEmployee Role : %s\n",ptr->data->role);
	printf("\tExperience : %d\n",ptr->data->experience);
	printf("\tEmployee Salary : %d\n",ptr->data->salary);
	printf("\n==========================\n");
	}
}

void update_by_id(struct employeeList *ptr)
{
	int id,flag=0;
	printf("\nEnter the ID of the employee you want to search : ");
	scanf("%d",&id);
	while(ptr->data->id != id)
	{
		if(ptr->link == NULL)
		{
			printf("ID not found!!");
			flag = 1;
			break;
		}
		
		else
		{
			ptr = ptr->link;
		}
	}
	if(flag != 1)
	{
	printf("\nUpdate the Values\n");
	
	printf("\n\nEnter the employee ID : ");
	scanf("%d",&ptr->data->id);
	fflush(stdin);
	printf("Enter the employee Name : ");
	gets(ptr->data->name);
	printf("Enter the employee Age : ");
	scanf("%d",&ptr->data->age);
	fflush(stdin);
	printf("Enter the employee Role : ");
	gets(ptr->data->role);
	printf("Enter the employee Experience : ");
	scanf("%d",&ptr->data->experience);
	printf("Enter the employee Salary : ");
	scanf("%d",&ptr->data->salary);
}
}



// Display function
void display(struct employeeList *ptr)
{
 	do
	{
		printf("\n==========================\n");
		printf("\tEmployee ID : %d\n",ptr->data->id);
		printf("\tEmployee Name : %s\n",ptr->data->name);
		printf("\tEmployee Age : %d\n",ptr->data->age);
		printf("\tEmployee Role : %s\n",ptr->data->role);
		printf("\tExperience : %d\n",ptr->data->experience);
		printf("\tEmployee Salary : %d\n",ptr->data->salary);
		printf("\n==========================\n\t|\n\t|\n\t|\n\t\\/\n");
		ptr = ptr->link;
	}while(ptr!= NULL);
}






//main function
void main()
{
	int opt;
	head = (struct employeeList*)malloc(sizeof(struct employeeList));
	printf("\n Creating a list...");
	create(head);
	printf("List Created");
	
	do
	{
		printf("\n1.Display Employee Data\n2.Insert Employee Data at start\n3.Insert Employee Data at End\n4.Insert Employee Data\n5.Delete Employee Data by ID\n6.Delete Employee Data at end\n7.Delete Employee Data at begin\n8.Search By Id\n9.Update By Id\n0.Exit\nChoose from the above : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				display(head);
				break;
			case 2:
				head = insert_at_begin(head);
				display(head);
				break;
			case 3:
				insert_at_end(head);
				display(head);
				break;
			case 4:
				insert(head);
				display(head);
				break;
			case 5:
				delete_at(head);
				display(head);
				break;
			case 6:
				delete_end(head);
				display(head);
				break;
			case 7:
				delete_begin(head);
				display(head);
				break;
			case 8:
				search_by_id(head);
				break;
			case 9:
				update_by_id(head);
			case 0:
				printf("\n\tTHANK YOU");
				break;
				
		}
	}while(opt !=0);
	
	
	
}








