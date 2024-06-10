#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5
int queue[N];
int front=-1;
int rear=-1;


void enqueue(int x);
void dequeue();
void display();

int main(){
    int choice,frequency;

    do{
    printf("\nWhat do you want?\n");
    printf("\n1.enqueue\n2.dequeue\n3.displace\n4.quit\n");
    printf("enter the choice:");
    scanf("%d",&choice);
    if(choice==1){
        printf("\nhow many times you want to enqueue?(<=5):");
        scanf("%d",&frequency);
        printf("\nNow enter the data:\n");
        for(int i=0;i<frequency;i++){
            int data;
            scanf("%d",&data);
            enqueue(data);
        }
    }
    if(choice==2){
         printf("\nhow many times you want to dequeue?()\n");
        scanf("%d",&frequency);
        for(int i=0;i<frequency;i++){
            dequeue();
        }
    }
    if(choice==3){
        display();
    }
    }while(choice!=4);
}

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    //condn if rear comes just before front in circular queue;
    else if((rear+1)%N==front){
        printf("\nqueue is full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("\nqueue is empty\n");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        printf("\ndequeued element:%d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    if(front==-1 && rear==-1)printf("\nqueue is empty\n");
    int i=front;
    while(i!=rear){
        printf("%d-->",queue[i]);
        i=(i+1)%N;
    }
    printf("%d\n",queue[i]);
}
