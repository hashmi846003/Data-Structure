#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
// Function to insert a node at the front of the list
void insertFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (*head);

    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }

    (*head) = newNode;
}
// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}
// Function to delete a node from the list
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        return;
    }

    if (*head == delNode) {
        *head = delNode->next;
    }

    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    free(delNode);
}
// Function to traverse and print the list
void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 6);
    insertFront(&head, 7);
    insertFront(&head, 1);
    insertEnd(&head, 4);

    printf("Created Doubly Linked List:\n");
    printList(head);

    deleteNode(&head, head->next);

    printf("List after deletion of second node:\n");
    printList(head);

    return 0;
}
