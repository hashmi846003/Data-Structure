#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Create linked list (append at end) */
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

/* Detect loop using slow & fast pointers */
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps

        if (slow == fast)
            return 1;   // loop detected
    }
    return 0;           // no loop
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

    if (detectLoop(head))
        printf("\nLoop detected in the linked list\n");
    else
        printf("\nNo loop detected in the linked list\n");

    return 0;
}
