#include<stdio.h>
#include<stdlib.h>
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
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next = head;
        head = newNode;


}
 while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


