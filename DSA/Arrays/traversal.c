#include<stdio.h>
#include<conio.h>


void trav(int* p,int n)
{
	int i;
	printf("Elemets are :\n");
	for(i=0;i<n;i++)
	{
		printf("%d",*(p+i));
	}
}

void main()
{
	int arr[50],n,i;
	printf("Enter the size of the array : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	trav(arr,n);
		
}
