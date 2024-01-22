#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 1000 

struct employeeNode {
    int id;
    char name[20];
    int age;
    char role[20];
    int experience;
    int salary;
};

int mergeComparisons = 0, mergeDataTransfers = 0;
int quickComparisons = 0, quickDataTransfers = 0;

void displayEmployees(struct employeeNode arr[], int n);
void displayStatistics(const char *sortType, int comparisons, int dataTransfers);
void merge(struct employeeNode arr[], int left, int middle, int right);
void mergeSort(struct employeeNode arr[], int left, int right);
int partition(struct employeeNode arr[], int low, int high);
void quickSort(struct employeeNode arr[], int low, int high);
void generateRandomIds(struct employeeNode[], int ) ;
int main() {
    srand(time(NULL));

    struct employeeNode employees[MAX_EMPLOYEES];
    int n = 0; 
    FILE *file = fopen("employee_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    while (fscanf(file, "%d %s %d %s %d %d",
                  &employees[n].id, employees[n].name, &employees[n].age,
                  employees[n].role, &employees[n].experience, &employees[n].salary) == 6) {
        n++;
        if (n >= MAX_EMPLOYEES) {
            printf("Too many employees. Increase MAX_EMPLOYEES.\n");
            break;
        }
    }
    
    
    fclose(file);
    printf("Before sort...\n");
    generateRandomIds(employees,n);
    displayEmployees(employees,  n);
    printf("\n\nSorted using merge sort...\n");
    
    mergeSort(employees,0, n-1);
    displayEmployees(employees,  n);
    
    
    
return 0;
}
void generateRandomIds(struct employeeNode arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i].id = rand() % 1000 + 1;  
    }
}
void displayEmployees(struct employeeNode arr[], int n) {
	
	int i;
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%s\t%d\t%d\n", arr[i].id, arr[i].name, arr[i].age,
               arr[i].role, arr[i].experience, arr[i].salary);
    }
}

void displayStatistics(const char *sortType, int comparisons, int dataTransfers) {
    printf("\n%s Statistics:\n", sortType);
    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of data transfers: %d\n", dataTransfers);
}

void merge(struct employeeNode arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    
    struct employeeNode L[n1], R[n2];

    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    mergeComparisons += (middle - left + 1) + (right - middle);
    mergeDataTransfers += (right - left + 1);
}

void mergeSort(struct employeeNode arr[], int left, int right) {
    if (left < right) {
    
        int middle = left + (right - left) / 2;

    
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

    
        merge(arr, left, middle, right);
    }
}

int partition(struct employeeNode arr[], int low, int high) {
    struct employeeNode pivot = arr[low];   
    int i = low;
	int j;
    for (j = low + 1; j <= high; j++) {
        if (arr[j].id <= pivot.id) {
            i++;

    
            struct employeeNode temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    
    struct employeeNode temp = arr[i];
    arr[i] = arr[low];
    arr[low] = temp;

    quickComparisons += (high - low);
    quickDataTransfers += (high - low + 1);

    return i;
}

void quickSort(struct employeeNode arr[], int low, int high) {
    if (low < high) {
    
    
        int pi = partition(arr, low, high);

    
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}






