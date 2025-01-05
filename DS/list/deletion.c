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

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* tempNode = head;

    if (position == 1) {  // Delete the first node
        head = head->nextNode;
        free(tempNode);
        return;
    }

    for (int i = 1; i < position - 1 && tempNode->nextNode != NULL; i++) {
        tempNode = tempNode->nextNode;
    }

    if (tempNode->nextNode == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* nodeToDelete = tempNode->nextNode;
    tempNode->nextNode = nodeToDelete->nextNode;
    free(nodeToDelete);
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

    printf("Deleting node at position 3:\n");
    deleteAtPosition(3);
    showLinkedList();

    return 0;
}
