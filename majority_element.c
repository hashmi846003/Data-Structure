#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    int candidate=-1;
    for(int i=0;i<n;i++){
        if(count==0){
            candidate=arr[i];
        }
        if(arr[i]==candidate){
            count++;
        }else{
            count--;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==candidate){
            count++;
        }
    }           
    if(count>n/2){
        printf("Majority element is %d\n",candidate);           
    }else{
        printf("No Majority Element\n");        


}
    free(arr);
    return 0;
}