#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* front=0;
struct node* rear=0;

void enqueue(int x){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }

}
void display(){
    struct node* temp;

    if(front==rear==0)printf("queue is empty");
    else{
        temp=front;
        while(temp!=0){
        printf("%d-->",temp->data);
        temp=temp->next;
        }
        printf("Null");
    }
}

void dequeue(){
    if(front==rear==0){
        printf("empty queue");
    }
    struct node* temp;
    temp=front;
    printf("\ndequeued data:%d\n",front->data);
    front=front->next;
    free(temp);
}
void peek(){
      if(front==rear==0){
        printf("\nempty queue\n");
    }
    printf("\nfront data:%d\n",front->data);
}

int main(){

    enqueue(5);
    enqueue(8);
    enqueue(10);
    enqueue(13);

    display();

    dequeue();
    dequeue();

    display();
    peek();



    return 0;
}