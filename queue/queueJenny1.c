#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 5
int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == n - 1)
        printf("\nOverFlow\n");

    else if (front == -1 && rear == -1)
    { // inserting at the beginning
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
    if (front == -1 && rear == -1)
    { // when the queue is empty
        printf("Underflow");
    }
    else if (front == rear)
    { // onekgula dequeue korar por jodi dekhi je front ar rear same node ke indicate kore
        front = rear = -1;
    }
    else
    {
        printf("\ndequed element: %d\n", queue[front]);
        front++; // eita korlei ager element ta garbage value hoye jabe.
    }
}

void display()
{
    if (front == -1 && rear == -1)
        printf("\nThere is nothung in the queue\n");

    for (int i = front; i < rear + 1; i++)
    {
        printf("%d-->", queue[i]);
    }
    printf("\n");
}

void peek()
{
    if (front == -1 && rear == -1)
        printf("\nThere is nothung in de queue\n");
    else
    {
        printf("%d", queue[front]);
    }
}

int main()
{

    enqueue(2);
    enqueue(4);
    enqueue(13);
    enqueue(12);
    enqueue(67);
    display();

    dequeue();
    dequeue();
    printf("\nAfteer dequeing two times:\n");
    display();

    printf("\nFront of the queue:\n");  
    peek();

    return 0;
}