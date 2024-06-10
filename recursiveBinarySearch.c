#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int key;


int binarySearch(int arr[],int l,int r){
    if(l>r){
        return -1;
    }
    int mid=(l+r)/2;
    if(key==arr[mid])return mid;
    else if(key<arr[mid])binarySearch(arr,l,mid-1);
    else if(key>arr[mid])binarySearch(arr,mid+1,r);
}

int main(){

    int arr[]={2,6,8,10,12,14,16,17,18,20};
    int n=sizeof(arr)/sizeof(arr[0]);
   
    printf("Enter element to search:");
    scanf("%d",&key);

    int a=binarySearch(arr,0,n-1);

    if(a==-1){
        printf("could not find element\n");
    }
    else{
        printf("found element at index %d\n",a);
    }


    return main();
}