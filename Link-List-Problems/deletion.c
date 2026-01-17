#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, val, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }

    
    printf("Original List:\n");
    temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);


    if (pos <= 0 || pos > n) {
        printf("Invalid position!\n");
    } else {
        temp = head;
        struct Node *prev = NULL;

        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) { 
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);

        
        printf("List after deletion:\n");
        temp = head;
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}