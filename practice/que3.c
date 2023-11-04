//Define a structure called candidate which contains candidate name, candidate political
//party, constituency number and number of votes received by the candidate. Write a
//program to read and display the details for n candidates. Define a function to display
//the details of the candidate for the given constituency number.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct candidate{
	
	char name[20];
	char party[15];
	unsigned int c_num;
	unsigned int votes;
	
};
typedef struct candidate cdt;

void search(cdt* candidates,int n,unsigned cdt_num){
	
	int i;
	for(i=0;i<n;i++)
	{
		if(candidates[i].c_num == cdt_num){
			printf("%u | %s | %s | %u",candidates[i].c_num,candidates[i].name,candidates[i].party,candidates[i].votes);
		}
	}
}
void print(cdt* candidates,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
			printf("%u | %s | %s | %u\n",candidates[i].c_num,candidates[i].name,candidates[i].party,candidates[i].votes);
	}

}
void main()
{
	int n,i,cand_num;
	cdt *candidates;
	
	
	printf("Enter the number of candidates : ");
	scanf("%d",&n);
	
	candidates = (cdt*)malloc(n*sizeof(cdt));
	
	for(i=0;i<n;i++)
	{
		printf("\Candidate-%d\n",i+1);
		printf("Enter the name : ");
		fflush(stdin);
		gets(candidates[i].name);
		printf("Enter the party : ");
		fflush(stdin);
		gets(candidates[i].party);
		printf("Enter the candidate number : ");
		scanf("%u",&candidates[i].c_num);
		printf("Enter the number of votes : ");
		scanf("%u",&candidates[i].votes);
	}
	print(candidates,n);
	printf("Enter the candidate to be searched : ");
	scanf("%d",&cand_num);
	search(candidates,n,cand_num);
	
	
}
