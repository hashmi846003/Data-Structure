#include <stdio.h>
#include <stdlib.h>

// Define a Node of the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to remove duplicates from a sorted linked list
struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return head;
    }
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
    return head;
}

// Helper function to create a linked list from an array
struct Node* createLinkedList(int* values, int size) {
    if (size == 0) {
        return NULL;
    }
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = values[0];
    head->next = NULL;
    struct Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct Node*)malloc(sizeof(struct Node));
        current = current->next;
        current->data = values[i];
        current->next = NULL;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);

    while (t--) {
        int n;
        printf("Enter length of the linked list: ");
        scanf("%d", &n);

        int* values = (int*)malloc(n * sizeof(int));
        printf("Enter the linked list values: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &values[i]);
        }

        struct Node* head = createLinkedList(values, n);
        head = removeDuplicates(head);
        printf("Linked list after removing duplicates: ");
        printLinkedList(head);

        // Free the linked list
        struct Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        free(values);
    }

    return 0;
}
