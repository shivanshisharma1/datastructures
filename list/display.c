#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* nextNode;
};

struct Node* head = NULL;

void buildLinkedList(int data[], int size) {
    struct Node *newNode, *tempNode;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->value = data[0];
    head->nextNode = NULL;
    tempNode = head;

    for (int i = 1; i < size; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = data[i];
        newNode->nextNode = NULL;
        tempNode->nextNode = newNode;
        tempNode = newNode;
    }
}

void showLinkedList() {
    struct Node* current = head;
    printf("Linked List (Iterative): ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->nextNode;
    }
    printf("END\n");
}

void showLinkedListRecursive(struct Node* current) {
    if (current == NULL) {
        printf("END\n");
        return;
    }
    printf("%d -> ", current->value);
    showLinkedListRecursive(current->nextNode);
}

int main() {
    int numbers[] = {12, 24, 36, 48, 60};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    buildLinkedList(numbers, size);

    showLinkedList();

    printf("Linked List (Recursive): ");
    showLinkedListRecursive(head);

    return 0;
}
