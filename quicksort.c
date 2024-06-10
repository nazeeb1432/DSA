#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>

void quicksort(int arr[],int lb,int ub);

int partition(int arr[],int lb,int ub);

void swap(int *p,int *q);

void PrintArray(int arr[], int n);

int main(){
    int n=50;
    int arr[n];
    for(int i=0;i<n;i++)arr[i]=rand()%500;

   // int arr[9]={7,6,10,5,9,2,1,15,7};
    //int n=sizeof(arr)/sizeof(arr[0]);
    int lb,ub;

    double start_time=(double)clock();

    quicksort(arr,0,n-1);

    printf("After sorting the array would be:");

    PrintArray(arr,n);

    double end_time=(double)clock();

    printf("Time to sort:%f",(double)(end_time-start_time)/CLOCKS_PER_SEC);

    return 0;
}

void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int partition(int arr[],int lb,int ub){

    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }

    swap(&arr[lb],&arr[end]);
    return end;
}

void swap(int *p,int *q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;

}

void PrintArray(int arr[], int n){
    int i;
    for(i =0; i< n; i++){
        printf("%d  ", arr[i]);
    }

    printf("\n");
}