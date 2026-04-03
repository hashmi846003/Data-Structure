#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* insertAtEnd(struct node *head, int data);
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
struct node* insertAtEnd(struct node *head, int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    new->data = data;
    new->link = NULL;
    if(temp==NULL){
        head=new;
    }
    while(temp->link!=NULL){
        temp=temp->link;

    }
    temp->link = new;

    return head;
}