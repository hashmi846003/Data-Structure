#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int sum(struct node *p);
int main(){
    struct node *head=NULL,*temp=NULL,*new=NULL;
    int data,n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&data);
        new->data=data;
        new->next=head;
        head=new;
        
    }


printf("Linked list (front insertion): ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    int total=sum(head);
    printf("Sum of data: %d\n", total);

    return 0;
}
int sum(struct node *p){
    int total=0;
    while (p!=NULL){
        total=total+p->data;
        p=p->next;
    }
    return total;
}