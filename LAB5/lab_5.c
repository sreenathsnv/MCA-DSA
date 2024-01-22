#include<stdio.h>
#include<stdlib.h>

int Lsearching(int arr[], int target, int n);
int SenSearching(int arr[], int target, int n);
int BinarySearch(int arr[], int n, int target);
void BubbleSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void swap(int arr[], int first, int second);

void main() {
	int i;
    int n, target;
    int arr[10];

    printf("\nEnter the number of integers to be printed:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Element: ");
        scanf("%d", &arr[i]);
    }
	printf("\nEnter the target:");
    scanf("%d", &target);
    int Lans = Lsearching(arr, target, n);
    printf("the answer found in linear search is %d index", Lans);

    int Sans = SenSearching(arr, target, n);
    printf("\nthe answer found in Sentinel search is %d index", Sans);

    BubbleSort(arr, n);
    printf("\nAfter Bubble sort\n");
    for (i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    InsertionSort(arr, n);
    printf("\nAfter Insertion sort\n");
    for (i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    int binAns = BinarySearch(arr, n, target);
    printf("\nthe answer found in Binary search is %d index", binAns);
}

int Lsearching(int arr[], int target, int n) {
	int i;
    if (n == 0) {
        return -1;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i + 1;
        }
    }

    return -1;
}

int SenSearching(int arr[], int target, int n) {
    
	int last = arr[n - 1];
    arr[n - 1] = target;

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[n - 1] = last;

    if (i < n - 1) {
        return i + 1;
    }

    return -1;
}

void BubbleSort(int arr[], int n) {
    short int swapped;
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 1; j < n - i; j++) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void InsertionSort(int arr[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for (j = i + 1; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr, j, j - 1);
            } else {
                break;
            }
        }
    }
}

void swap(int arr[], int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int BinarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + (end - start) / 2);

        if (target < arr[mid]) {
            end = mid - 1;
        } else if (target > arr[mid]) {
            start = mid + 1;
        } else {
            return mid + 1;
        }
    }

    return -1;
}

