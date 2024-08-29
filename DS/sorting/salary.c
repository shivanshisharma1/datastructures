#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    float salary;
};

void swap(struct Employee *xp, struct Employee *yp) {
    struct Employee temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(struct Employee arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j].salary < arr[min_idx].salary)
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printEmployees(struct Employee arr[], int size) {
    int i;
    printf("Name\t\tSalary\n");
    for (i = 0; i < size; i++)
        printf("%s\t%.2f\n", arr[i].name, arr[i].salary);
}

int main() {
    struct Employee arr[] = {{"John Doe", 50000}, {"Jane Smith", 75000},
        {"Sam Brown", 45000}, {"Emily Davis", 60000}};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original list of employees:\n");
    printEmployees(arr, n);

    selectionSort(arr, n);

    printf("\nSorted list of employees by salary:\n");
    printEmployees(arr, n);

    return 0;
}
