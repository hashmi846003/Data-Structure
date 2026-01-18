o#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
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
