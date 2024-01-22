#include <stdio.h>
#include <stdlib.h>

struct employeeNode {
    int id;
    char name[20];
    int age;
    char role[20];
    int experience;
    int salary;
};

struct node {
    struct node* left;
    struct employeeNode* data;
    struct node* right;
};
struct node* root = NULL;
struct node* createNode() {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = (struct employeeNode*)malloc(sizeof(struct employeeNode));
    printf("Enter the employee Id: ");
    scanf("%d", &n->data->id);
    printf("Enter the employee Name: ");
    fflush(stdin);
    fgets(n->data->name, sizeof(n->data->name), stdin);
    printf("Enter the employee age: ");
    scanf("%d", &n->data->age);
    printf("Enter the employee Role: ");
    fflush(stdin);
    fgets(n->data->role, sizeof(n->data->role), stdin);
    printf("Enter the employee experience: ");
    scanf("%d", &n->data->experience);
    printf("Enter the employee salary: ");
    scanf("%d", &n->data->salary);

    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node* insertBST(struct node* root, struct employeeNode* newData) {
    if (root == NULL) {
        struct node* newNode = createNode();
        newNode->data = newData;
        root = newNode;
        return newNode;
    }

    if (newData->id < root->data->id) {
        root->left = insertBST(root->left, newData);
    } else if (newData->id > root->data->id) {
        root->right = insertBST(root->right, newData);
    }

    return root;
}


void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
               root->data->id, root->data->name, root->data->age,
               root->data->role, root->data->experience, root->data->salary);
        inOrderTraversal(root->right);
    }
}


void preOrderTraversal(struct node* root) {
    if (root != NULL) {
        printf("ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
               root->data->id, root->data->name, root->data->age,
               root->data->role, root->data->experience, root->data->salary);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
               root->data->id, root->data->name, root->data->age,
               root->data->role, root->data->experience, root->data->salary);
    }
}


struct node* search(struct node* root, int id) {
    if (root == NULL || root->data->id == id) {
        return root;
    }

    struct node* leftResult = search(root->left, id);
    if (leftResult != NULL) {
        return leftResult;
    }

    return search(root->right, id);
}

int height(struct node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}


struct node* deleteNode(struct node* root, int id) {
    if (root == NULL) {
        return root;
    }

    if (id < root->data->id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->data->id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root->data);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root->data);
            free(root);
            return temp;
        }

        struct node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data->id);
    }

    return root;
}

int main() {
    int choice, id;
    struct employeeNode* newData;
	printf("creating root node.....");
	root = insertBST(root, newData);
    do {
        printf("\n1. Insert Node");
        printf("\n2. In-order Traversal");
        printf("\n3. Pre-order Traversal");
        printf("\n4. Post-order Traversal");
        printf("\n5. Search Node");
        printf("\n6. Delete Node");
        printf("\n7. Calculate Height");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newData = (struct employeeNode*)malloc(sizeof(struct employeeNode));
    			insertBST(root, newData);
                break;
            case 2:
                printf("\nIn-order Traversal:\n");
                inOrderTraversal(root);
                break;
            case 3:
                printf("\nPre-order Traversal:\n");
                preOrderTraversal(root);
                break;
            case 4:
                printf("\nPost-order Traversal:\n");
                postOrderTraversal(root);
                break;
            case 5:
                printf("\nEnter the ID to search: ");
                scanf("%d", &id);
                struct node* searchResult = search(root, id);
                if (searchResult != NULL) {
                    printf("Node found: ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
                           searchResult->data->id, searchResult->data->name, searchResult->data->age,
                           searchResult->data->role, searchResult->data->experience, searchResult->data->salary);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 6:
                printf("\nEnter the ID to delete: ");
                scanf("%d", &id);
                root = deleteNode(root, id);
                printf("Node with ID %d deleted.\n", id);
                break;
            case 7:
                printf("\nHeight of the tree: %d\n", height(root));
                break;
            case 8:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

   
    return 0;
}

