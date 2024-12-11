#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;
    int value;

    printf("Enter the values (-1 to stop):\n");

    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }

        // Allocate memory for a new node
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        newnode->data = value;
        newnode->next = NULL;

        // Add the new node to the linked list
        if (head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
    }

    // Print the linked list
    temp = head;
    printf("Linked list is:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free the allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
