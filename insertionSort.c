#include <math.h>
#include <stdio.h>
#include<time.h>
 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than temp, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
/* Driver program to test insertion sort */
int main()
{   
    int n=50;
    int arr[n];
    for(int i=0;i<n;i++)arr[i]=rand()%10;
    double start_time = (double)clock();
    //int arr[] = { 12, 11, 13, 5, 6 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    printArray(arr, n);

    double end_time = (double)clock();
    double total_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;//clockspersecond is long int type
    printf("\nTotal Time: %f s\n", total_time);
 
    return 0;
}