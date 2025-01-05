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

void reverseLinkedList() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void showLinkedList() {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->nextNode;
    }
    printf("END\n");
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    buildLinkedList(numbers, size);
    showLinkedList();

    printf("Reversing the linked list:\n");
    reverseLinkedList();
    showLinkedList();

    return 0;
}
