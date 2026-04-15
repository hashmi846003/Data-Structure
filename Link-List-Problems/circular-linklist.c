#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* insert_end(Node *head, int value) {
    Node *new = malloc(sizeof(Node));
    new->data = value;

    if (head == NULL) {
        new->next = new; // points to itself
        return new;
    }

    Node *temp = head;
    while (temp->next != head) { // stop at last node
        temp = temp->next;
    }

    temp->next = new;
    new->next = head; // new node points back to head
    return head;
}

void print_list(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    Node *head = NULL;

    // Insert array elements into circular linked list
    for (int i = 0; i < 5; i++) {
        head = insert_end(head, arr[i]);
    }

    // Print the circular linked list
    print_list(head);

    return 0;
}
