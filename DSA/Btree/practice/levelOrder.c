#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

void createLevel(struct node *root, int level)
{
    if (level == 0)
    {
        printf("enter data : ");
        scanf("%d", &root->data);
        root->left = NULL;
        root->right = NULL;
    }
    else if (level > 0)
    {
        if (root->left == NULL)
        {
            root->left = (struct node *)malloc(sizeof(struct node));
        }
        createLevel(root->left, level - 1);

        if (root->right == NULL)
        {
            root->right = (struct node *)malloc(sizeof(struct node));
        }
        createLevel(root->right, level - 1);
    }
}

void display(struct node *root, int level)
{
    if (root != NULL)
    {
        if (level == 0)
        {
            printf("\t%d", root->data);
        }
        if (level > 0)
        {
            display(root->left, level - 1);
            display(root->right, level - 1);
        }
    }
    else
    {
        printf("\tEmpty");
    }
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));

    int level, i;
    printf("Enter your max height: ");
    scanf("%d", &level);

    for (i = 0; i < level; i++)
    {
        createLevel(root, i);
    }

    printf("\ncreated\n");
    
    for (i = 0; i < level; i++)
    {
        printf("\nLevel %d:", i);
        display(root, i);
    }

    return 0;
}

