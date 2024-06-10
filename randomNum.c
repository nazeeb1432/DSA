#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(){

    int arr[50];
    for(int i=0;i<50;i++){
        arr[i]=rand()%501;
        printf("%d,",arr[i]);
    }

    return 0;
}