#include<stdio.h>
#include<stdlib.h>
#include "D:/Christ/2MCA\DSA/Lab2/Employee.h"


struct employeeList *front  = NULL, *rear = NULL;


void enque()
{
	struct employeeList* ptr = (struct employeeList*)malloc(sizeof(struct employeeList));
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
	ptr->link = NULL;
	if(front == NULL && rear == NULL)
	{
		front = ptr;
		rear = ptr;
	}	
	
	else
	{
		rear->link = ptr;
		rear = ptr;
	}
	printf("Add more data..(y/n) : ");
	c = getche();
	if(c == 'y')
		enque();
	else
		printf("\n\n\tQueue created!");
	
}
void deque()
{
	struct employeeList* temp;
	char c;
	if(front ==NULL && rear ==NULL)
	{
		printf("\n\t Queue is Empty..");
	}
	else
	{
		if(front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		temp = front;
		front = front->link;
		free(temp);
	}
	printf("\ndelete More..(y/n) : ");
	c= getche();
	if(c == 'y')
		deque();
	else
		printf("");
	}
	
	
}

void display()
{
	struct employeeList* ptr = front;
	if(front == NULL && rear == NULL)
	{
		printf("\n\tQueue is empty..\n\tNo Data!\n");
	}
	else
	{
		while(ptr != NULL)
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
		}	
	}
	
}

void searchById()
{
	int n;
	struct employeeList *ptr = front;
	printf("\nEnter the ID of the employee : ");
	scanf("%d",&n);
	
	while(ptr!= NULL)
	{
		if(ptr->data->id == n)
		{
			break;	
		}	
		ptr = ptr->link;
	}
	if(ptr!= NULL)
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
	else
	{
		printf("\n\t No Data Found!!\n");
	}
}


void main()
{
	
	int opt;
		
	do
	{
		printf("\n1.Add Employee data\n2.Display All\n3.Delete Data\n4.Search Employee By ID\n0.Exit\nChoose from the above : ");
		scanf("%d",&opt);
		
		switch(opt)
		{
			case 1:
				enque();
				break;
			case 2:
				display();
				break;
			case 3:
				deque();
				break;
			case 4:
				searchById();
				break;
			case 0:
				printf("\n\tTHANK YOU");
				break;
				
		}
	}while(opt !=0);
	
	
	
}
