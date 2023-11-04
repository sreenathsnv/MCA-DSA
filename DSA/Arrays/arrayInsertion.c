#include<stdio.h>
#include<conio.h>

int arr[50],n;

void insert(int *arr,int pos,int val)
{
	int i;
	for(i=n-1;i>=pos;i--)
	{
		arr[i+1] = arr[i];
	}
	arr[pos] = val;
	n++;
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
	insert(arr,pos,val);
	insert(arr,6,240);
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
}
