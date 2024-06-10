#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    //condn if rear comes just before front in circular queue
    else if((rear+1)%N==front)
        printf("queue is full\n");
    else{
        rear=(rear+1)%N;//typical rear++ and last e chole ashle abar front e pathay if jayga is empty
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1)printf("queue is empty\n");
    else if(front==rear){
        //mane dequeue korte korte jodi front==rear hoye jayy
        front=rear=-1;
    }
    //real mal niche
    else{
        printf("\nDequeued element-->%d\n",queue[front]);
        front=(front+1)%N;//front last e ele jeno ghure abar shamne jete pare jehetu circular queue;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    int i=front;
    printf("Queue is:");
    while(i!=rear){
        printf("%d-->",queue[i]);
        i=(i+1)%N;
    }
    printf("%d",queue[i]);
    
}
int main(){

    // int choice,frequency;

    // do{
    // printf("\nWhat do you want?\n");
    // printf("\n1.enqueue\n2.dequeue\n3.displace\n4.quit\n");
    // printf("enter the choice:");
    // scanf("%d",&choice);
    // if(choice==1){
    //     printf("\nhow many times you want to enqueue:");
    //     scanf("%d",&frequency);
    //     printf("\nNow enter the data:\n");
    //     for(int i=0;i<frequency;i++){
    //         int data;
    //         scanf("%d",&data);
    //         enqueue(data);
    //     }
    // }
    // if(choice==2){
    //      printf("\nhow many times you want to dequeue?()\n");
    //     scanf("%d",&frequency);
    //     for(int i=0;i<frequency;i++){
    //         dequeue();
    //     }
    // }
    // if(choice==3){
    //     display();
    // }
    // }while(choice!=4);
    
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    display();
    dequeue();
    dequeue();

    enqueue(10);
    enqueue(11);

    display();

    return 0;
}