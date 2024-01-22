

struct employeeNode{
	
	int id;
	char name[20];
	int age;
	char role[20];
	int experience;
	int salary;	
};

struct employeeList
{
	struct employeeNode *data;
	struct employeeList *link;
};

struct employeeList *head;
char opt;

