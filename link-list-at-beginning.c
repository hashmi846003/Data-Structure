#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
};
int main(){
    struct Node *head=NULL,*newNode=NULL;
    int data,n;
    printf("Enter the number of Node");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data\n");
        scanf("%d",&data);
        newNode->data=data;
        newNode->next = head;
        head = newNode;
printf("Linked List: ");
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }



}
}