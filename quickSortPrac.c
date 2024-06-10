#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int arr[],int first,int last);
int partition(int arr[],int first,int last);
void selection_sort(int arr[],int n);

void swap(int *p,int *q);

int main(){
    int n=30;
    int arr[n];
    for(int i=0;i<n;i++)arr[i]=rand()%30;
    //selection_sort(arr,n);
    double start_time = (double)clock();

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }

    double end_time = (double)clock();
    double total_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;//clockspersecond is long int type
    printf("\nTotal Time: %f s\n", total_time);


}

void quicksort(int arr[],int first,int last){

    if(first>=last)return;

    int pi=partition(arr,first,last);
    quicksort(arr,first,pi-1);
    quicksort(arr,pi+1,last);

}
int partition(int arr[],int first,int last){
    int piv=arr[last];
    int i=first-1;//used to insert elements<pivot;
    int j=first;//used to find element<pivot;
    for(;j<last;j++){
    if(arr[j]<piv){
        i++;
        swap(&arr[i],&arr[j]);
    }
    }
    swap(&arr[i+1],&arr[last]);

    return i+1;

}
void selection_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void swap(int *p,int *q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}