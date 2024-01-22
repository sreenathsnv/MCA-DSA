
#include<stdio.h>
#include<stdlib.h>


struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node* root = NULL;
int k=0;
// function to create a node 

struct node* create(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
};

struct node* insert(struct node *root,int data)
{
	
	if(root == NULL)
	{
		root = create(data);
		return root;
	}
			
	if(root->data<data)
	{
		root->right = insert(root->right,data);
	}
	if(root->data>data)
	{
		root->left = insert(root->left,data);
	}
	return root;
	
}

void traversal(struct node* root)
{
	if(root== NULL)
	{
		printf("...");
	}
	else
	{
		printf("| %d |",root->data);
		traversal(root->left);
		traversal(root->right);
	}
}

int search(struct node*root,int data)
{
	if(root==NULL)
	{
		printf("Element not fount..");
		k = 0;
		return -1;
	}
	if(root->data<data)
	{
		
		k += search(root->right,data);
	}
	if(root->data>data)
	{
		k += search(root->right,data);
	}
	if(root->data == data)
	{
		return k;
	}
}

void main()
{
	int arr[] = {1,2,3,4,8,1,9,3,9},i;
	
	root = create(2);
	
	for(i=0;i<9;i++)
	{
		insert(root,arr[i]);
	}
	
	traversal(root);
	printf("search 3 : %d",search(root,3));
}



