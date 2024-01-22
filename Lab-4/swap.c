#include<stdio.h>


void swapbyref(int *x,int *y)
{
	int t;
    t = *x;
    *x = *y;
    *y = t;
}

void swap(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void main()
{
	int a=10,b=19;
	
	printf("Call by value\n");
	printf("\nBefore swap : a = %d b = %d",a,b);
	swap(a,b);
	printf("\n After swap : a = %d b = %d",a,b);
	
	printf("\n\nCall by reference\n");
	printf("\nbefoer swap : a = %d b = %d",a,b);
	swapbyref(&a,&b);
	printf("\n After swap : a = %d b = %d",a,b);
	
}
