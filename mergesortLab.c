#include<stdio.h>
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

    if(l >= r){
        return;
    }else{
        int mid = (l+r)/2; // 0+99-1/2

        mergesort(arr, l, mid); // recursive call
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

int main(){

    clock_t start_time = clock();
    
    printf("Starting time: %f second(s)\n", (float)start_time/CLOCKS_PER_SEC);
    
//average case:int arr[] = {7,406,105,487,113,52,490,57,498,388,50,439,80,421,131,253,129,309,208,28,341,260,339,411,194,425,29,226,283,100,299,36,6,150,269,366,202,259,169,199,393,219,384,473,386,262,473,14,317,180};
//Best case:int arr[]={6,7,14,28,29,36,50,52,57,80,100,105,113,129,131,150,169,180,194,199,202,208,219,226,253,259,260,262,269,283,299,309,317,339,341,366,384,386,388,393,406,411,421,425,439,473,473,487,490,498};
    int arr[]={498,490,487,473,473,439,425,421,411,406,393,388,386,384,366,341,339,317,309,299,283,269,262,260,259,253,226,219,208,202,199,194,180,169,150,131,129,113,105,100,80,57,52,50,36,29,28,14,7,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printf("%d \n",n);
    printf("\nArray before sorting: ");  
    PrintArray(arr, n);

    mergesort(arr, 0, n - 1);

    printf("Array after sorting: ");
    PrintArray(arr, n);

    clock_t end_time = clock();
    printf("\nEnding time: %f seconds\n", (float)end_time/CLOCKS_PER_SEC);

    double total_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;
    printf("\nTotal Time: %f s\n", total_time);

    return 0;
}