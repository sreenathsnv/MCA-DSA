#include<stdio.h>


int indexcmp =0, transop=0, valcmp =0, totalcmp = 0;

void selSort(int arr[],int n)
{
	int min,usi=0;
	int i,j,temp;
	
	for(j=0;j<n-1;j++)
	{
		indexcmp++;
		totalcmp++;
		min = j;
		transop++;
		
		for(i = j;i<n;i++)
		{
			indexcmp++;
			totalcmp++;
			if(arr[i]<arr[min])
			{
				valcmp++;
				totalcmp++;
				min = i;
				transop++;
			}
		}
	
		temp = arr[j];
		
		arr[j] = arr[min];
		arr[min] = temp;
		transop += 3;
		
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
	
	printf("Sorted array : ");
	
	selSort(arr,n);
	display(arr,n);
	
	printf("\nGenerate Report...");
	printf("\nIndex Comparisons : %d",indexcmp);
	printf("\nData transfer : %d",transop);
	printf("\nValue comparison : %d",valcmp);
	printf("\nTotal comparison : %d",totalcmp);
	
	
}
