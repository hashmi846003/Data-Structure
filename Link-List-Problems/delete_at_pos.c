#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Append node at end (create list) */
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

/* Delete node at given position */
struct Node* deleteAtPos(struct Node* head, int pos) {

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    /* Case 1: Delete first node */
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    /* Case 2: Delete middle or last node */
    struct Node* temp = head;

    for (int i = 1; temp->next != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

/* Print list */
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

    /* Create list */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = append(head, data);
    }

    printf("\nLinked List:\n");
    printList(head);

    /* Delete at position */
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    head = deleteAtPos(head, pos);

    printf("\nLinked List after deletion:\n");
    printList(head);

    return 0;
}
