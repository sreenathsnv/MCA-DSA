//Create the student database to store the roll number, name class and marks of 3
//subjects for n students. Display the student details in a formatted way. Implement
//modify and search operation in a structure.

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct student{
	
	unsigned int rollno;
	char name[20];
	char className[10];
	unsigned int mark1;
	unsigned int mark2;
	unsigned int mark3;	
	
};

void sort(struct student[],int);
void print(struct student[],int);
void modify(struct student[],int,int);


void main()
{
	int i=0,n=3,regno;
	struct student students[10];
	
	for(i=0;i<n;i++)
	{
		printf("\tStudent-%d\n",i+1);
		printf("Enter the roll number : ");
		scanf("%u",&students[i].rollno);
		printf("Enter the name : ");
		fflush(stdin);
		gets(students[i].name);
		printf("Enter the class : ");
		fflush(stdin);
		gets(students[i].className);
		printf("Enter the mark1 : ");
		scanf("%u",&students[i].mark1);
		printf("Enter the mark2 : ");
		scanf("%u",&students[i].mark2);
		printf("Enter the mark3 : ");
		scanf("%u",&students[i].mark3);	
	}
	print(students,n);
	sort(students,n);
	print(students,n);	
	
	printf("enter the regno of student to be modified :");
	scanf("%d",&regno);
	modify(students,n,regno);
	print(students,n);	
}

void print(struct student students[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\tStudent-%d\n",i+1);
		printf("| Regno : %u |\n",students[i].rollno);
		printf("| name : %s |\n",students[i].name);
		printf("| Class : %s |\n",students[i].className);
		printf("| Mark1 : %u |\n",students[i].mark1);
		printf("| mark2 : %u |\n",students[i].mark2);
		printf("| mark3 : %u |\n",students[i].mark3);
	}
}
void sort(struct student students[],int n)
{
	int i,j;
	struct student temp;
	//sorting using regno
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(students[i].rollno<students[j].rollno)
			{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
			}	
		}
	}
		
}

void modify(struct student students[],int n,int regno)
{
	int i,index;
	for(i=0;i<n;i++)
	{
		if(students[i].rollno== regno){
			fflush(stdin);
			printf("Enter the new name : ");
			gets(students[i].name);
			fflush(stdin);
			printf("Enter the new class : ");
			gets(students[i].className);
			printf("Enter the new mark1 : ");
			scanf("%u",&students[i].mark1);
			printf("Enter the new mark2 : ");
			scanf("%u",&students[i].mark2);
			printf("Enter the new mark3 : ");
			scanf("%u",&students[i].mark3);
			break;
		}
	}
	
}


















