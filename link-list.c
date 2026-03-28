#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main(){
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;
    int n,data;
    printf("Enter the number of Nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data\n");
        scanf("%d",&data);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else if(temp->next==NULL){
            temp->next=newNode;
            temp=newNode;
        }
    }
      temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

return 0;

}