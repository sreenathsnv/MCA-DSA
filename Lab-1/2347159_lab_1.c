
//Domain : Employee management


#include<stdio.h>

int arr[20][20],row,col;


void read(int (*arr)[20]){
	
	int i,j;
	printf("\nEnter the number of rows :");
	scanf("%d",&row);
	printf("\nEnter the number of columns :");
	scanf("%d",&col);
	printf("Enter the elements (id,age,salary)\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",(*(arr+i)+j));
			
		}
	}	
}

int  search_employee(int (*arr)[20],int id)
{
	int i;
	for(i=0;i<row;i++)
	{
		if(arr[i][0] == id)
		{
			return i;
		}
		
	}
	return -1;
	
}

void add()

{
	unsigned short r1,c1,i,j;
	float arr1[20][20],arr2[20][20];
	printf("Enter the number of rows : ");
 	scanf("%hu",&r1);
 	printf("Enter the number of columns : ");
 	scanf("%hu",&c1);
	printf("Enter the Elements of the first matrix\n");
 	for(i=0;i<r1;i++)
 	{
 		for(j=0;j<c1;j++)
 		{
 			printf("matrix_1(%hu %hu ) = ",i+1,j+1);
 			scanf("%f",&arr1[i][j]);
 		}
 	}
 	printf("Enter the Elements of the second matrix\n");
 	for(i=0;i<r1;i++)
 	{
 		for(j=0;j<c1;j++)
 		{
 			printf("matrix_2(%hu %hu ) = ",i+1,j+1);
 			scanf("%f",&arr2[i][j]);
 		}
 	}
	printf("\n\n");
 	for(i=0;i<r1;i++)
 	{
 		for(j=0;j<c1;j++)
 		{
 			printf("| %.2f |",arr1[i][j]+arr2[i][j]);
 		}
 		printf("\n");
 	}
}

void print(int (*arr)[20])
{
	int i,j;
	printf("ID Age \t Salary\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %d ",*(*(arr+i)+j));
		}
		printf("\n");
	}	
}

void transpose()
{
	
	unsigned short r1,c1,i,j;
	float arr1[20][20],arr2[20][20];
	printf("Enter the number of employee data to be added : ");
 	scanf("%hu",&r1);
 	printf("Enter the number of columns u want : ");
 	scanf("%hu",&c1);
	printf("Enter the Elements of the first matrix\n");
 	for(i=0;i<r1;i++)
 	{
 		for(j=0;j<c1;j++)
 		{
 			printf("matrix_1(%hu %hu ) = ",i+1,j+1);
 			scanf("%f",&arr1[i][j]);
 		}
 	}
	for (i = 0; i < r1; i++) {
 		for (j = 0; j < c1; j++) {
 			arr2[j][i] = arr1[i][j];
 		}
 	}
 
 	printf("\n\n");
 	for (i = 0; i < c1; i++) {
 		for (j = 0; j < r1; j++) {
 			printf("| %.2f |", arr2[i][j]);
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
	printf("\nEnter employee id , employee age and employee salary\n");
	read(arr);
	
	
	do{
		printf("\n1.List Employee details \n 2.insert employee data \n 3.delete employee data by ID\n 4.Search Employee by Id\n5.matrix addition\n6.Transpose of a matrix\n7.exit\n Choose from the above : ");
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
				break;
			case 4:
				printf("\nEnter the id of the employee to be search : ");
				scanf("%d",&n);
				n = search_employee(arr,n);
				if(n == -1)
				{
					printf("Id not found");
					break;
				}
				printf("Employee id : %d\n Employee age : %d\n Employee salary : %d",arr[n][0],arr[n][1],arr[n][2]);
				break;
			case 5:
				add();
				break;
			case 6:
				transpose();
				break;
			case 7:
				printf("\n\t\tThank You");
				break;
			default:
				printf("Invalid input!!");
				
				
		}
	}while(opt != 7);
}
