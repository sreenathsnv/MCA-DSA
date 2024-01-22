#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};


struct node* createPreorder(struct node* root)
{
	char y;
	printf("\nEnter the data : ");
	scanf("%d",&root->data);
	root->left = NULL;
	root->right = NULL;
	printf("\nDo you want to create a left subtree for %d ?(y/n) : ",root->data);
	y = getche();
	if(y =='y')
	{
		root->left = (struct node*)malloc(sizeof(struct node));
		root->left = createPreorder(root->left);	
	}
	
	printf("\nDo you want to create a right subtree for %d ?(y/n) : ",root->data);
	y = getche();
	if(y =='y')
	{
		root->right = (struct node*)malloc(sizeof(struct node));
		root->right = createPreorder(root->right);	
	}
	return root;
	
}

void display(struct node* root)
{
	if(root != NULL)
	{
		printf("\t| %d |\t\n",root->data);
		display(root->left);
		display(root->right);
	}
	else
	{
		printf(".");
	}
}


void main()
{
	struct node* root = (struct node*)malloc(sizeof(struct node));
	createPreorder(root);
	display(root);
}
