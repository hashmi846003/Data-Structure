#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void link_list_traversal(struct node *head);
void insert_in_between(struct node *head,int data,int index);
int main(){
struct node *head=NULL,*temp=NULL,*newNode=NULL;
int n,value;
printf("Enter the nummber of nodes\n");
scanf("%d",&n);
for (int i=0;i<n;i++){
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &value);
    newNode->data=value;
    newNode->next=NULL;
    if (head==NULL){
        head=newNode;
        temp=newNode;
    }else{
        temp->next=newNode;
        temp=newNode;
    }

}
 printf("\nLinked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
void link_list_traversal(struct node *head){
    struct node *temp = head;
    printf("\nLinked List:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_in_between(struct node *head,int data,int index){
struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *temp = head;
    int i = 0;

    // Traverse to the node just before the desired index
    while (i < index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        free(ptr);
        return;
    }

    ptr->next = temp->next;
    temp->next = ptr;
}