#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(){

    double meanTotal=78.94;
    double sum=0.0,x;
    double store;
    for(int i=0;i<16;i++){
        scanf("%lf",&x);
        store=(x-meanTotal)*(x-meanTotal);
        sum=sum+store;
    }

    printf("SSt-> %lf",sum);

    return 0;
}