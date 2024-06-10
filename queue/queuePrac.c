#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
int queue[N];

int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
        printf("Queue is full");
    else if (front ==-1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        
        queue[rear++] = x;
    }
}
void dequeue()
{
    if (front ==-1 && rear==-1)
        printf("\nQueue is empty\n");
    else
    {
        printf("\ndequed element ->%d\n", queue[front]);
        front++;
    }
}
void display()
{

    if (front ==rear==-1)
        printf("Queue is empty");
    for (int i = front; i <= rear; i++)
    {
        printf("%d-->", queue[i]);
        if (i == rear)
            printf("\n");
    }
}
void peek()
{
    if (front ==rear==-1)
        printf("Queue is empty");
    else
    {
        printf("\nfront element ->%d\n", queue[front]);
    }
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();


    dequeue();
    dequeue();

    display();
    printf("before dequeuing:");
    peek();
    printf("After dequeuing:");
    dequeue();
    peek();

    return 0;
}