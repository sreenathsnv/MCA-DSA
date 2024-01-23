#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};


struct node* createInorder(struct node* root)
{
	int data;
	char y;
	
		printf("\nEnter data : ");
		scanf("%d",&data);
	printf("\nwant left node for (%d) : ",data);
	y = getche();
	if(y== 'y')
	{
		root->left = (struct node*)malloc(sizeof(struct node));
		root->left = createInorder(root->left);
	}
	else
	{
		root->left = NULL;
	}

	root->data = data;
	
	printf("\nwant right node for (%d) : ",data);
	y = getche();
	if(y== 'y'){
	
	root->right = (struct node*)malloc(sizeof(struct node));
	root->right = createInorder(root->right);
	
	}
	else
	{
		root->right = NULL;
	}

	return root;
	
}

void display(struct node* root)
{
	if(root != NULL)
	{
		display(root->left);
		printf(" %d ",root->data);
		display(root->right);
	}
	else
	{
		printf("\t");
	}
}

void main()
{
	struct node *root = (struct node*)malloc(sizeof(struct node));
	createInorder(root);
	display(root);
}
