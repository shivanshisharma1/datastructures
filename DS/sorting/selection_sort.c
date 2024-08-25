#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n-1; i++) {
        min = i;

        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 8, 3, 7, 1};
    int n = 6; 
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n-1; i++) {
        min = i;

        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 8, 3, 7, 1};
    int n = 6; 
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

    return 0;
}

