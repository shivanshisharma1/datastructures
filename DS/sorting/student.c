#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    int n, i;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter the marks of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i+1);
        scanf("%d", &marks[i]);
    }

    printf("Original marks: \n");
    printArray(marks, n);
    
    bubbleSort(marks, n);
    
    printf("Sorted marks: \n");
    printArray(marks, n);
    
    return 0;
}
