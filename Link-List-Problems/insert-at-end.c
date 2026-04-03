#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* insertAtBeginning(struct node *head, int data);
int main(){
    struct node *head,*temp,*newnode;
    int n,data;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&data);
        newnode->data=data;
        newnode->link=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp=newnode;
            temp->link=newnode;

        }
    }
}
struct node* insertAtBeginning(struct node *head, int data){
     struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = head;   
    head = newnode;         
    return head;
}