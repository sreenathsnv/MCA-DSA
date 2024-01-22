
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100



char isOperator(char op)
{
	return(op == '*' || op == '/' ||op == '+' ||op == '-' ||op == '^');
}


int precedence(char op)
{
	switch(op)
	{
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '-':
		case '+':
			return 1;
		default :
			return -1;
	}
}

char* infixToPost(char* infix)
{
	int i,j;
	int len = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char)*(len+2));
	char stack[MAX_SIZE];
	int top = -1;
	for(i=0,j=0;i<len;i++)
	{
		if(infix[i]== ' ' || infix[i] == '\t')
		{
			continue;
		}
		else if(isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
			
		}
		else if(isOperator(infix[i]))
		{
			while(top>-1 && precedence(stack[top]) >=precedence(infix[i]) )
			{
				postfix[j++] = stack[top--];
			
				
			}
			stack[++top] = infix[i];
			
		}
		else if(infix[i]=='(')
		{
			stack[++top]  = infix[i];
		}
		else if(infix[i]== ')')
		{
			while(top>-1 && stack[top] !='(')
			{
				postfix[j++] = stack[top--];
				
				
			}
			top--;
		}
		
	}
	while(top>-1)
		{
			postfix[j++] = stack[top--];
		}
		postfix[j++] = '\0';
	return postfix;
	
	
}

void main()
{
	char* express = "(a+b)-c*d/e";
	puts(infixToPost(express));
}
