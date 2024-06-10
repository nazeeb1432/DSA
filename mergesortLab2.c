#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int l, int mid, int r)
{
    int an = mid - l + 1;//3
    int bn = r - mid;//2
    // create two temp arrays
    int a[an];
    int b[bn];

    for (int i = 0; i < an; i++)
    {
        a[i] = arr[l + i];
    }
    for (int j = 0; j < bn; j++)
    {
        b[j] = arr[mid + 1 + j];
    }
    int i = 0; // initial index of first subarray a;
    int j = 0; // initial index of second subarray b;
    int k = l; // initial index of merged subarray;

    while (i < an && j < bn)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }

    while (i < an)
    {
        arr[k++] = a[i++];
    }
    while (j < bn)
    {
        arr[k++] = b[j++];
    }
}

void mergesort(int arr[], int l, int r){

    if(l == r){
        return;
    }else{
        int mid = (l+r)/2; 

        mergesort(arr, l, mid); 
        mergesort(arr, mid+1, r);

        merge(arr, l, mid, r);

    }
    
}

void PrintArray(int arr[], int n){
    int i;
    for(i =0; i< n; i++){
        printf("%d  ", arr[i]);
    }

    printf("\n");
}

void selection_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){

    
    //int n = sizeof(arr)/ sizeof(arr[0]);
    int n=30000;
    int arr[n];

    for(int i=0;i<n;i++) arr[i]=rand()%9000;

    // printf("\nArray before sorting: ");  
    // PrintArray(arr, n);
    //selection_sort(arr,n);//can comment out for average case

    double start_time = (double)clock();

    mergesort(arr, 0, n - 1);

    printf("Array after sorting: ");
    PrintArray(arr, n);

    double end_time = (double)clock();
    //printf("\nEnding time: %f seconds\n", (float)end_time/CLOCKS_PER_SEC);

    double total_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;//clockspersecond is long int type
    printf("\nTotal Time: %f s\n", total_time);

    return 0;
}