#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(){

    int data[]={1,56,12,34,8,99,657};
    int max=data[0];
    int index=0;
    int i=0;
    while(i<7){
        if(max<data[i])
        {
            max=data[i];
            index=i;
        };
        i++;
    }
    printf("maximum element is %d aat index %d",max,index);

    return 0;
}