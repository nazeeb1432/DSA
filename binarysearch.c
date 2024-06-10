#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int BinarySearch(int arr[],int n,int key);

int main(){

    int arr[]={5,9,17,23,25,45,59,63,71,89};    //must be sorted
    int key;
    printf("Enter element to search:");
    scanf("%d",&key);

    int index=BinarySearch(arr,10,key);

    if(index==-1)printf("element not found");
    else if(index)printf("Element found at index %d",index);


    return 0;
}
int BinarySearch(int arr[],int n,int key){
    int l,r,mid;
    l=0,r=n-1;

    while(l<=r){
        mid=(l+r)/2;
        if(key==arr[mid])return mid;
        else if(key<arr[mid])r=mid-1;
        else l=mid+1;
    }

    return -1;


}