#include<stdio.h>

#include<stdlib.h>

#include<time.h>
int index;
int findElement(int arr[],int key,int size);

int main(){

    int arr[]={5,9,17,23,25,45,59,63,71,89}; 
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("Enter Key:");
    
    scanf("%d",&key);
    double start_time=(double)clock();
    int search=findElement(arr,key,size);

    if(search==1)printf("Element Found at index %d\n",index);
    else if(search==-1)printf("Element not found\n");

    double end_time=(double)clock();
    printf("Total time is %f seconds",(double)(end_time-start_time)/CLOCKS_PER_SEC);
    return 0;
}
int findElement(int arr[],int key,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            index=i;
            return 1;
        }
    }
    return -1;
}