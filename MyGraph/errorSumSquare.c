#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    double y,x;
    double b0=85.05;
    double b1=0.21;

    double sum=0;
    double store;

    for (int i=1;i<=12;i++){
        scanf("%lf %lf",&x,&y);
        store=(y-b0-b1*x)*(y-b0-b1*x);
        sum=sum+store;
    }

    printf("\nError sum square:%lf",sum);

}