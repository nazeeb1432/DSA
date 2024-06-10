#include<stdio.h>

int returnMax(int *ptr,int n){
    int max=0;
    for(int i=0;i<n;i++){

        if(ptr[i]>max){
            max=ptr[i];
        }
    }

    return max;


}

int main(){

    int arr[]={1,12,3,54,5,67,654};
    int max=returnMax(arr,7);
    printf("Maximum element in this array is %d\n",max);
    int temp;
    for(int i=0;i<7;i++){
        for(int j=i;j<7;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}