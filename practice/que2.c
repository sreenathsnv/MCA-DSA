//Define a structure called cricketer which contains the player name, team name and
//batting average. Define a function to read and display the details for n cricketers.
// Define a function to search for the given cricketer. If the name is matching, then
//display the details of the cricketer. If the given name is not matching, then display an
//appropriate message.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct cricketer{
	
	char name[20];
	char team[20];
	float avg;
	
};
typedef struct cricketer ck;
void print(ck*,int);

void search(ck*,int,char[]);

void main()
{
	int n,i;
	char name[20];
	printf("Enter the Number of students : ");
	scanf("%d",&n);
	ck *cricketers;
	
	cricketers = (ck*)malloc(n*sizeof(ck));
	
	for(i=0;i<n;i++)
	{
		printf("\tCricketer-%d\n",i+1);
		printf("Enter the name : ");
		fflush(stdin);
		gets(cricketers[i].name);
		printf("Enter the team : ");
		fflush(stdin);
		gets(cricketers[i].team);
		printf("Enter the batting average : ");
		scanf("%f",&cricketers[i].avg);
	}
	
	print(cricketers,n);
	fflush(stdin);
	printf("Enter the name to be searched : ");
	gets(name);
	
	search(cricketers,n,name);
	
}

void print(ck* cricketers,int n){
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d | %s | %s | %f |\n",i+1,cricketers[i].name,cricketers[i].team,cricketers[i].avg);
	}
	
}

void search(ck* cricketers,int n,char name[])
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(cricketers[i].name,name) == 0)
		{
			printf("%d | %s | %s | %f |\n",i+1,cricketers[i].name,cricketers[i].team,cricketers[i].avg);
			flag =1;
			break;
		}
		
		
	}
	if(flag == 0)
		printf("No data found!");
}












