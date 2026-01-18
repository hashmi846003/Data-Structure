#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!head)
        return newNode;

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void removeDuplicatesUnsorted(struct Node* head) {
    struct Node *current, *runner, *temp;

    for (current = head; current != NULL; current = current->next) {
        runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
    }
}

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
        scanf("%d", &data);
        head = append(head, data);
    }

    printf("\nBefore removing duplicates:\n");
    printList(head);

    removeDuplicatesUnsorted(head);

    printf("\nAfter removing duplicates:\n");
    printList(head);

    return 0;
}
