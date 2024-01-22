#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* root;

struct node* create(int level)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (level == 0)
    {
        printf("Enter the data : ");
        scanf("%d", &temp->data);
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (level > 0)
    {
        temp->left = create(level - 1);
        temp->right = create(level - 1);
    }
    return temp;
}

void displayByLevel(struct node* root, int level)
{
    if (root == NULL)
    {
        printf("|   |"); // Print an empty space for NULL node
        return;
    }

    if (level == 0)
    {
        printf("| %d |", root->data);
    }
    else if (level > 0)
    {
        displayByLevel(root->left, level - 1);
        displayByLevel(root->right, level - 1);
    }
}

int main()
{
    int height, i;
    printf("Enter the levels : ");
    scanf("%d", &height);
    
    root = create(height);

    for (i = 0; i < height; i++)
    {
        displayByLevel(root, i);
    }

    return 0;
}


