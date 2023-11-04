
//Domain : Employee management


#include<stdio.h>

int arr[20][20],arr1[20][20],res[20][20],row,col;


void read(int (*arr)[20]){
	
	int i,j;
	printf("\nEnter the number of rows :");
	scanf("%d",&row);
	printf("\nEnter the number of columns :");
	scanf("%d",&col);
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",(*(arr+i)+j));
			
		}
	}	
}

void print(int (*arr)[20])
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %d ",*(*(arr+i)+j));
		}
		printf("\n");
	}	
}


void insert_employee(int arr[][20],int row_pos)
{
	int i,j;
	if(row_pos<=row+1 && row_pos>=0)
	{
		for(i=row-1;i>=row_pos;i--)
		{
			for(j=0;j<col;j++)
			{
				arr[i+1][j] = arr[i][j];
			}
		
		}
		printf("Enter Employee id : ");
		scanf("%d",&arr[row_pos][0]);
		printf("Enter Employee age : ");
		scanf("%d",&arr[row_pos][1]);
		printf("Enter Employee salary : ");
		scanf("%d",&arr[row_pos][2]);
		row++;
	}
}

void delete_employee(int (*arr)[20],int id)
{
	int i,j,index = -1;
	for(i = 0;i<row;i++)
	{
		if(**(arr+i) == id)
		{
			index = i;
			break;
		}
	}
	if(index != -1)
	{
		for(i= index;i<row-1;i++)
		{
			for(j=0;j<col;j++)
			{
				*(*(arr+i)+j) = *(*(arr+(i+1))+j); 
			}
		}
		row--;
	}
	else
		printf("Id not found!!");
}
void main()
{
	int opt,n;
	col = 3;
	read(arr);
	printf("\nEnter employee id , employee age and employee salary\n");
	
	do{
		printf("\n1.print\n 2.insert\n 3.delete\n 4.exit\n Choose from the above : ");
		scanf("%d",&opt);
	
		switch(opt)
		{
			case 1:
				print(arr);
				break;
			case 2:
				printf("\nIn which row u want to insert elements : ");
				scanf("%d",&n);
				insert_employee(arr,n);
				break;
			case 3:
				printf("\nEnter the id of the employee to be delete : ");
				scanf("%d",&n);
				delete_employee(arr,n);
		}
	}while(opt != 4);
}
