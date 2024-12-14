#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    // Create and initialize nodes
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *current = NULL;

    // Allocate memory for the nodes
    one = (struct node*) malloc(sizeof(struct node));
    two = (struct node*) malloc(sizeof(struct node));
    three = (struct node*) malloc(sizeof(struct node));

    // Assign data to nodes
    one->data = 1;
    two->data = 2;
    three->data = 3;

    // Connect first node
    // with the second node
    one->next = two;
    
    // Connect second node
    // with the third node
    two->next = three;

    // make next pointer of
    //third node to NULL
    //indicates last node
    three->next = NULL;

    //connect previous nodes
    one->prev = NULL;
    two->prev = one;
    three->prev = two;
   
    // Save address of first node in head
    head = one;
    current = head;

    // print the linked list values forward
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}