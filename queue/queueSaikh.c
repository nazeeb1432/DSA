#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct queue
{
    int data;
    int front, rear, capacity, size ;
    int *arr ;
} queue;

bool isFull( queue *Q );
bool isEmpty( queue *Q );
queue *createQueue( int capacity );
void enqueue( queue *Q, int data );
int dequeue( queue *Q );
void printQueue( queue *Q );
int inFront( queue *Q );
int inBack( queue *Q );



int main()
{
    queue *que = malloc(sizeof(queue));
    que = createQueue(20); 
    que->size = 5 ;

    enqueue( que, 4);
    enqueue( que, 7);
    enqueue( que, 5);
    printQueue( que );
    printf("%d\n",inFront(que));
    printf("%d\n",inBack(que));

    enqueue( que, 1);
    enqueue( que, 13);
    enqueue( que, 9);

    printQueue( que );

    dequeue( que );
    dequeue( que );
    dequeue( que );
    printQueue( que );

    printf("%d\n", dequeue( que ));
    dequeue( que );
    dequeue( que );
    printQueue( que );
    
}

queue *createQueue( int capacity )
{
    queue *Q = malloc(sizeof(queue));
    Q->front = Q->rear = -1;
    Q->capacity = capacity ;
    Q->arr = malloc(sizeof(int)*capacity);
    return Q ;
}

void enqueue( queue *Q , int data )
{
    if ( isFull(Q) )
    {
        printf("Can't insert any data in the queue. \n");
    }
    else if ( isEmpty(Q) )
    {
        Q->front = Q->rear = 0 ;
        Q->arr[0] = data ;
    }
    else
    {
        Q->arr[ ++( Q->rear )] = data ;
    }
}

int dequeue( queue *Q )
{
    if ( isEmpty(Q) )
    {
        printf("Can't pop any data from the queue. \n");
    }
    else
    {
        return Q->arr[Q->front++];
    }   
}

bool isFull( queue *Q )
{
    if ( (Q->rear-Q->front+1) >= Q->size )
    {
        printf("The queue is full. \n");
        return true ;
    }
    return false ;
}

bool isEmpty( queue *Q )
{
    if( Q->front > Q->rear || (Q->front==-1 && Q->rear==-1) )
    {
        printf("The Queue is Empty.\n");
        return true;
    } 
    return false ;
}

void printQueue( queue *Q )
{
    int i = Q->front, j = Q->rear ;
    if ( isEmpty(Q) )
    {
        printf("No data to show.\n");
        return ;
    }
    for( ; i <= j ; i++ )
    {
        printf("%d\t", Q->arr[i]);
    }
    printf("\n");
}

int inFront( queue *Q )
{
    return Q->arr[Q->front];
}

int inBack( queue *Q )
{
    return Q->arr[Q->rear];
}