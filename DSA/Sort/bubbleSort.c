#include<stdio.h>





void Bsort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]  = temp; 
			}
		}
	}
}

void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d,",arr[i]);
	}
}

void main()
{
	
	int arr[100],n,i;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	printf("\nEnter the elements : ");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Actual array : ");
	
	display(arr,n);
	
	Bsort(arr,n);
	printf("sorted array : ");
	display(arr,n);
	
	
}
