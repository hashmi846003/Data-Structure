#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head,*temp,*newnode;
    int n;
    int data;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d", &data);
        newnode->data=data;
        newnode->next=NULL;
        if (head==NULL){
            head=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    print_element( )
}