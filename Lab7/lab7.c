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
	printf("Enter the the employee Id : ");
	scanf("%d",&n->data->id);
	printf("Enter the the employee Name : ");
	fflush(stdin);
	gets(n->data->name);
	printf("Enter the the employee age : ");
	scanf("%d",&n->data->age);
	printf("Enter the the employee Role : ");
	fflush(stdin);
	gets(n->data->role);
	printf("Enter the the employee experience : ");
	scanf("%d",&n->data->experience);
	printf("Enter the the employee salary : ");
	scanf("%d",&n->data->salary);
	
	n->left = NULL;
	n->right  =NULL;
	
	return n;
}


struct node* insertLevelOrder(struct node* root) {
    if (!root) {
        return createNode();
    }

    
    struct node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct node* temp = queue[++front];

        if (!temp->left) {
            temp->left = createNode();
            break;
        } else {
            queue[++rear] = temp->left;
        }

        if (!temp->right) {
            temp->right = createNode();
            break;
        } else {
            queue[++rear] = temp->right;
        }
    }

    return root;
}

struct node* insertDepthOrder(struct node* root) {
    if (!root) {
        return createNode();
    }

    struct employeeNode* newData = createNode()->data;

    if (newData->id < root->data->id) {
        root->left = insertDepthOrder(root->left);
    } else {
        root->right = insertDepthOrder(root->right);
    }

    return root;
}

void inOrderTraversal(struct node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
               root->data->id, root->data->name, root->data->age,
               root->data->role, root->data->experience, root->data->salary);
        inOrderTraversal(root->right);
    }
}


void preOrderTraversal(struct node* root) {
    if (root) {
        printf("ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
               root->data->id, root->data->name, root->data->age,
               root->data->role, root->data->experience, root->data->salary);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("ID: %d, Name: %s, Age: %d, Role: %s, Experience: %d, Salary: %d\n",
               root->data->id, root->data->name, root->data->age,
               root->data->role, root->data->experience, root->data->salary);
    }
}

int main() {
	int opt;
	printf("creating the root node...\n");
	root = insertLevelOrder(root);
    
    do{
	
		printf("\n1.create by Level order\n2.Inorder traversal\n3.Pre Order Traversal\n4.Post order\n5.create by depth order\n0.Exit\nChoose from the above : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				insertLevelOrder(root);
				break;
			case 2:
				 printf("In-order traversal:\n");
    			inOrderTraversal(root);
				break;
			case 3:
				printf("\nPre-order traversal:\n");
    			preOrderTraversal(root);
				break;
			case 4:
				 printf("\nPost-order traversal:\n");
   				 postOrderTraversal(root);
				break;
			case 5:
				printf("\nDepth level insertion:\n");
   				insertDepthOrder(root);
				break;
			case 0:
				printf("\n\tTHANK YOU");
				break;
				
		}
	}while(opt !=0);
	
	
    return 0;
}

