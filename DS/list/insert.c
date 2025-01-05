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

void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;

    if (position == 1) {  // Insert at the beginning
        newNode->nextNode = head;
        head = newNode;
        return;
    }

    struct Node* tempNode = head;
    for (int i = 1; i < position - 1 && tempNode != NULL; i++) {
        tempNode = tempNode->nextNode;
    }

    if (tempNode == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->nextNode = tempNode->nextNode;
    tempNode->nextNode = newNode;
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

    printf("Inserting 25 at position 3:\n");
    insertAtPosition(25, 3);
    showLinkedList();

    return 0;
}
