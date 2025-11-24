#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};
// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        newNode->next = newNode; // Point to itself if the list is empty
        *head = newNode;
        return;
    }

    while (last->next != *head) {
        last = last->next;
    }

    last->next = newNode;
}
// Function to insert a node at the front of the circular linked list
void insertFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        newNode->next = newNode; // Point to itself if the list is empty
        *head = newNode;
    } else {
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        *head = newNode;
    }
}
// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        return;
    }

    struct Node *temp = *head, *prev;

    // If the node to be deleted is the head node
    if (temp->data == key) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    // Find the node to be deleted
    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted is found
    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    }
}
// Function to traverse and print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 6);
    insertFront(&head, 7);
    insertFront(&head, 1);
    insertEnd(&head, 4);

    printf("Created Circular Linked List:\n");
    printList(head);

    deleteNode(&head, 1);

    printf("List after deletion of node with data 1:\n");
    printList(head);

    return 0;
}
