#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=NULL,*temp=NULL,*New=NULL;
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        New = (struct node*)malloc(sizeof(struct node));
        New->data = data;
        New->next = NULL;

        if (head == NULL) {
            head = New;   // first node
            temp = head;
        } else {
            temp->next = New;  // link new node
            temp = temp->next; // move temp forward
        }
    }

    // Print the linked list
    printf("Linked list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
