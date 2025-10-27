/*write a menu driven c program to implement an array in C: 
1. Traverse and display element 
2. search for an element (linear search) 
3. Insert an element at any position (start, middle and end) 
4. Delete an element from any position*/

#include <stdio.h>

void traverse(int arr[], int n);
void search(int arr[], int n, int target);
void insert(int arr[], int *n, int position, int value);
void deletion(int arr[], int *n, int position);

int main() {
    int n, choice, value, position, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[100];  // fixed size for simplicity

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Search\n");
        printf("3. Insert\n");
        printf("4. Deletion\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, n);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &target);
                search(arr, n, target);
                break;

            case 3:
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &position);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(arr, &n, position, value);
                break;

            case 4:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &position);
                deletion(arr, &n, position);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

void traverse(int arr[], int n) {
    printf("Elements in the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search(int arr[], int n, int target) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Element not found\n");
    }
}

void insert(int arr[], int *n, int position, int value) {
    if (position < 1 || position > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = value;
    (*n)++;
    printf("Element inserted successfully.\n");
}

void deletion(int arr[], int *n, int position) {
    if (position < 1 || position > *n) {
        printf("Invalid position!\n");
        return;
    }
    printf("Deleted element: %d\n", arr[position - 1]);
    for (int i = position - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}

