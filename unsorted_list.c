#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

void insert(node **head,int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
        else {
             node* current = *head;
              while (current->next != NULL) {
                 current = current->next; } 
                 current->next = newnode;  
    }

}
void removeDuplicates(node* head) {
    if (head == NULL) return;

    node* current = head;
    node* prev = NULL;
    node* temp;
    int hash[1000] = {0};  // Adjust size as needed
    while (current != NULL) {
        if (hash[current->data]) {
            // Duplicate found, remove it
            prev->next = current->next;
            temp = current;
            current = current->next;
            free(temp);
        } else {
            // Mark this element as seen
            hash[current->data] = 1;
            prev = current;
            current = current->next;
        }
    }
}
void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    node* head = NULL;
    insert(&head, 10);
    insert(&head, 12);
    insert(&head, 11);
    insert(&head, 11);
    insert(&head, 12);
    insert(&head, 11);
    insert(&head, 10);
    printf("Original List: \n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: \n");
    printList(head);

    return 0;
}
