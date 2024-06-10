#include<stdio.h>

void quicksort(int list[], int low, int high);

int pivot(int list[], int low, int high);

int main(void)
{
    int arr[]= {1, 5, 8, 2, 3, 7, 5, 8, 9, 4, 6};
    quicksort(arr, 0, 10);
    for(int i=0; i<11; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}

void quicksort(int list[], int low, int high)
{
    if(low<high)
    {
        int pivLoc= pivot(list, low, high);
        quicksort(list, low, pivLoc-1);
        quicksort(list, pivLoc+1, high);
    }
}

int pivot(int list[], int low, int high)
{
    int piv = list[high], i= low-1, j, temp;
    for(j= low; j<high; j++)
    {
        if(list[j] < piv)
        {
            i++;
            temp= list[i];
            list[i]= list[j];
            list[j]= temp;
        }
    }

    i++;
    temp= list[i];
    list[i]= list[high];
    list[high]= temp;

    return i;
}