#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Insert node at the end (used to create list) */
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Insert node at given position */
struct Node* insertAtPos(struct Node* head, int data, int pos) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

/* Print linked list */
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, pos;

    /* Step 1: Create Linked List */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = append(head, data);
    }

    printf("\nLinked List created:\n");
    printList(head);

    /* Step 2: Insert at Position */
    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    printf("Enter position: ");
    scanf("%d", &pos);

    head = insertAtPos(head, data, pos);

    printf("\nLinked List after insertion:\n");
    printList(head);

    return 0;
}
