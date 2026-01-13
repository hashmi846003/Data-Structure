#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev; // new head
}

// Utility to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Helper to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printf("Original List:\n");
    printList(head);

    head = reverse(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}