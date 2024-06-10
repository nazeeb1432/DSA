#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bublesort(int *arr,int n);
int findmax(int arr[],int n);
void countsort(int arr[],int n,int place);
void radix_sort(int arr[],int n);

int main(int argc,char *argv[])
{

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=rand()%n;
    
    //bublesort(arr,n);

    double start_time = (double)clock();

    radix_sort(arr,n);

    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    double end_time = (double)clock();
    double total_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;
    printf("total time is:%lf",total_time);

    return 0;
}

void bublesort(int *arr,int n){
    int i,j,temp;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void radix_sort(int arr[],int n){
    int max=findmax(arr,n);

    for(int place=1;(max/place)>0;place*=10){
        countsort(arr,n,place);
    }
}

void countsort(int arr[],int n,int place){
    int output[n];
    int count[10]={0};

    for(int i=0;i<n;i++) count[(arr[i]/place)%10]++;

    for(int i=1;i<10;i++) count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--){
        int index=count[(arr[i]/place)%10]-1;
        output[index]=arr[i];
        count[(arr[i]/place)%10]--;
    }

    for(int i=0;i<n;i++) arr[i]=output[i];
}

int findmax(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }

    return max;
}
