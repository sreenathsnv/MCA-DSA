#include<stdio.h>


int indexcmp =0, transop=0, valcmp =0, totalcmp = 0;

void insSort(int arr[],int n)
{
	int key;
	int i,j;
	
	for(j=1;j<n;j++)
	{
		indexcmp++;
		key = arr[j];
		transop++;
		i = j-1;
		transop++;
		while(i>=0 && arr[i]>key)
		{
			valcmp++;
			transop++;
			indexcmp++;
			arr[i+1] = arr[i];
			i = i-1;
			transop++;	
		}
		transop++;
		arr[i+1]  = key;	
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
	
	insSort(arr,n);
	display(arr,n);
	
	printf("\nGenerate Report...");
	printf("\nIndex Comparisons : %d",indexcmp);
	printf("\nData transfer : %d",transop);
	printf("\nValue comparison : %d",valcmp);
	printf("\nTotal comparison : %d",totalcmp);
	
	
}
