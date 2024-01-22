#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct patient
{
	int ID;
	int age;
	int level;
};

int SIZE = 0;
struct patient* Pque[100];

int front = -1,rear = -1;

void enque()
{
	int lev,i;
	char c;
	struct patient *temp;
	struct patient *ele = (struct patient*)malloc(sizeof(struct patient));
	printf("\nEnter the Patient ID : ");
	scanf("%d",&ele->ID);	
	printf("Enter the Patient Age : ");
	scanf("%d",&ele->age);
	printf("Enter the Patient Severity (1-5) : ");
	scanf("%d",&ele->level);
	if(ele->level>5 || ele->level<1)
	{
		printf("Invalid severity level!! Level should be between 1-5");
		printf("Enter the Patient Severity (1-5) : ");
		scanf("%d",&ele->level);
	}
	if(front == -1 && rear == -1)
	{
		
		front++;
		rear++;
		Pque[front] = ele;
		
	}
	if(SIZE>=100)
	{
		printf("\n\tOverflow!! Delete some items");
	}
	
	else if(ele->level<=Pque[rear]->level)
	{
		Pque[++rear] = ele;
		
	}
	else{
		
		for(i=SIZE;i>=0;i--)
		{
			if(ele->level>Pque[i]->level)
			{
				continue;
			}
			else
			{
				lev = i+1;
				break;
			}
		}
		for(i=SIZE;i>=lev;i--)
			{
				Pque[i+1] = Pque[i];
			}
			Pque[lev] = ele;
			rear++;
			
		
	}
	SIZE++;
	
	printf("\n\tAdd more data (y/n) : ");
	c = getche();
	if(c == 'y')
	{
		enque();
	}
	else
	{
		printf("\n\t Queue Created");
	}
}

void display()
{
	int i;
	for(i=SIZE-1;i>=0;i--)
	{
		if(front == -1 && rear == -1)
		{
			printf("\nQueue is empty!!");
			break;
		}
		printf("\n\t===========================\n");
		printf("Patient ID : %d\n",Pque[i]->ID);
		printf("Patient Age : %d\n",Pque[i]->age);
		printf("Patient Severity level : %d\n",Pque[i]->level);
		printf("================================\n\t\t|\n");
	}
}

void display_highest()
{
	int i,highest =5;
	for(i=0;i<=SIZE;i++)
	{
		if(front == -1 && rear == -1)
		{
			printf("\nQueue is empty!!");
			break;
		}
		if(Pque[i]->level<highest)
		{
			highest = Pque[i]->level;
		}
	}
		for(i=0;i<=SIZE;i++)
	{
		if(front == -1 && rear == -1)
		{
			break;
		}
		if(Pque[i]->level == highest)
		{
		printf("\n\t===========================\n");
		printf("Patient ID : %d\n",Pque[i]->ID);
		printf("Patient Age : %d\n",Pque[i]->age);
		printf("Patient Severity level : %d\n",Pque[i]->level);
		printf("================================\n\t\t|\n");
		}
	}
	
	
}

void getFrequency()
{
	int one=0,two=0,three=0,four=0,five=0,i;
	for(i=0;i<=SIZE;i++)
	{
		switch(Pque[i]->level)
		{
			case 1:
				one++;
				break;
			case 2:
				two++;
				break;
			case 3:
				three++;
				break;
			case 4:
				four++;
				break;
			case 5:
				five++;
				break;
			
		}
	}
	
	printf("\n\tFrequecy Table ");
	printf("\nSeverity Level 1: %d" , one);
	printf("\nSeverity Level 2 : %d" , two);
	printf("\nSeverity Level 3 : %d" , three);
	printf("\nSeverity Level 4 : %d" , four);
	printf("\nSeverity Level 5 : %d" , five);
	
	
	
	
}



void main()
{
	int op;

	do
	{
		printf("\n1.Add data\n2.Display All\n3.Display highest priority data\n4.Get frequency Count\nType 0 for exit\n\tChoose from above : ");
		fflush(stdin);
		scanf("%d",&op);
			switch(op)
		{
		case 1:
			enque();
			break;
		case 2:
			display();
			break;
		case 3:
			display_highest();
			break;
		case 4:
			getFrequency();
			break;
		case 0:
			printf("\n\tThank you");
			break;
		default:
			printf("invalid Input");
		}
	}while(op != 0);
}


