#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int key;
int ind;
int findElement(int arr[]);

int main(){

    int arr[]={34,56,12,9,89,33,62};
    printf("Enter Key:");
    
    scanf("%d",&key);
    int search=findElement(arr);

    if(search==1)printf("Element Found at index %d\n",ind);
    else if(search==-1)printf("Element not found\n");
    return main();
}
int findElement(int arr[]){
    for(int i=0;i<7;i++){
        if(arr[i]==key){
            ind=i;
            return 1;
        }
    }
    return -1;
}