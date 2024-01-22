#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};


struct node* postOrder(struct node* root)
{
	int data;
	char y;
	printf("\nEnter data :");
	scanf("%d",&data);
	
	printf("\nWant left node for %d : ",data);
	y = getche();
	if(y == 'y')
	{
		root->left = (struct node*)malloc(sizeof(struct node));
		root->left = postOrder(root->left);
	}
	else
	{
		root->left = NULL;
	}
	printf("\nWant right node for %d : ",data);
	y = getche();
	if(y == 'y')
	{
		root->right = (struct node*)malloc(sizeof(struct node));
		root->right = postOrder(root->right);
	}
	else
	{
		root->right = NULL;
	}
	root->data = data;
	return root;
}

void display(struct node* root)
{
	if(root != NULL)
	{
		display(root->left);
		display(root->right);
		printf(" %d ",root->data);
	}
}

void main()
{
	struct node* root = (struct node*)malloc(sizeof(struct node));
	postOrder(root);
	display(root);
}
