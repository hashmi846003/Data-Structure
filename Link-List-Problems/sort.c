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

/* Sort linked list using Bubble Sort (data swapping) */
void sortList(struct Node* head) {
    if (head == NULL)
        return;

    int swapped;
    struct Node* ptr;
    struct Node* last = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
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
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = append(head, data);
    }

    printf("\nBefore sorting:\n");
    printList(head);

    sortList(head);

    printf("\nAfter sorting:\n");
    printList(head);

    return 0;
}
