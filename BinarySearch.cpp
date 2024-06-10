#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[],int n,int key);
int main(){

    int arr[10]={5,25,17,9,63,23,45,71,89,59};
    int n=sizeof(arr)/sizeof(arr[0]);//syntax to know the size of an array
    cout<<n<<endl;
    sort(arr,arr+10);
     int key;
    printf("Enter element to search:");
    scanf("%d",&key);

    int index=BinarySearch(arr,10,key);

    if(index==-1)printf("element not found");
    else if(index)printf("Element found at index %d\n",index);
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