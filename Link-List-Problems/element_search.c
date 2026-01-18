#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Append node at end */
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

/* Search element in linked list */
int search(struct Node* head, int key) {
    int pos = 1;

    while (head != NULL) {
        if (head->data == key)
            return pos;

        head = head->next;
        pos++;
    }

    return -1;   // Not found
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
    int n, data, key, pos;

    /* Create linked list */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = append(head, data);
    }

    printf("\nLinked List:\n");
    printList(head);

    /* Search element */
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    pos = search(head, key);

    if (pos != -1)
        printf("Element %d found at position %d\n", key, pos);
    else
        printf("Element %d not found in the list\n", key);

    return 0;
}
