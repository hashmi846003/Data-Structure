#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int position(struct node *head,int data,int pos){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (pos == 1) {
        newnode->next = head;
        return newnode;
    }

    struct node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}


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
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp=newnode;
            temp->next=newnode;

        }
    }
}