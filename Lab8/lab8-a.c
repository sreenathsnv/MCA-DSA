#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE); 
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node *findMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int data) {
    if (root == NULL) {
        printf("Element %d not found in the tree\n", data);
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


Node *search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int height(Node *root) {
    if (root == NULL) {
        return -1; 
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node *root = NULL;

	int i,n,val;
	printf("How many node u want? : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the value : ");
		scanf("%d",&val);
		root = insert(root,val);
	}

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");


    int searchKey;
    printf("Enter a value to search: ");
    scanf("%d", &searchKey);
    Node *searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Element %d found in the tree\n", searchKey);
    } else {
        printf("Element %d not found in the tree\n", searchKey);
    }

    int deleteKey;
    printf("Enter a value to delete: ");
    scanf("%d", &deleteKey);
    root = deleteNode(root, deleteKey);
    printf("Deleted %d from the tree\n", deleteKey);

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

  
    printf("Height of the tree: %d\n", height(root));

    return 0;
}

