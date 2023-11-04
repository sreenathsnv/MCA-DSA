#include<stdio.h>
#include<conio.h>

int n;

void insert(int arr[],int pos,int val)
{
	int i;
	if(n<pos)
	{
		printf("Invalid position value");
		
	}
	else if(pos == n)
		arr[n] = arr[n-1];
	else{
		
		for(i=n-1;i>=pos;i--)
		{
			arr[i+1] = arr[i];
		}
		arr[pos] = val;
		
	}
	n++;
	
	
}

void main()
{
	int arr[50],i;
	
	printf("NTR size : ");
	scanf("%d",&n);
	printf("Enter the element");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	
	insert(arr,5,5);
	printf("%d",n);
	printf("%d",arr[n-1]);
	
	for(i=0;i<n;i++)
	{
		printf("%d",*(arr+i));
	}
	
	
}
