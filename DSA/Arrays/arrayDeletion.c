#include<stdio.h>
#include<conio.h>

int arr[50],n;


void delete(int* arr,int pos)
{
	int i;
	for(i = pos;i<n-1;i++)
	{
		arr[i] = arr[i+1];
	}
	n--;
	
}

void delete_by_value(int *arr,int val)
{
	int i,index;
	for(i=0;i<n;i++)
	{
		if(arr[i] == val)
			{
				index = i;
				break;
			}
			
	}
	delete(arr,index);
}

void main()
{
	int pos,val,i;
	printf("Enter the size : ");
	scanf("%d",&n);
	printf("\nEnter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	printf("\nEnter the Value : ");
	scanf("%d",&val);
	delete(arr,pos);
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
}
