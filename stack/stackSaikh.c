#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

stack* createStack( int size );
bool isEmpty(stack *s);
bool isFull(stack *s);
void push( stack *s, int data );
int pop( stack *s );
int peek( stack *s, int pos );
int inTop( stack *s );
int inBottom ( stack *s );
void printStack( stack *s );

int main()
{
    stack *st = createStack(5);

    printStack(st);
    push( st, 13 );
    push( st, 17 );
    push( st, 28 );
    printf("%d\n", pop( st ));
    printStack(st);
    push( st, 7 );
    push( st, 10 );
    push( st, 12 );
    printStack(st);

    pop( st );
    pop( st );
    printStack(st);
    printf("%d\n", pop( st ));
    pop( st );
    pop( st );
    pop( st );
    push( st, 12 );
    printStack(st);
    
}

stack* createStack( int size )
{
    stack* s = malloc(sizeof(stack));
    s->size = size ;
    s->arr = malloc(sizeof(int)*size);
    s->top = -1 ;
}

bool isEmpty( stack *s )
{
    if ( s->top == -1 )
    {
        printf("The Stack is Empty. \n");
        return  true;
    }
    
    return false ;
}

bool isFull(stack *s)
{
    if ( s->top >= s->size-1 )
    {
        printf("The Stack is full. \n");\
        return true ;
    }
    
    return false ;
}

void push( stack *s, int data )
{
    if ( !isFull(s) )
    { 
        s->arr[ ++(s->top) ] = data ;
    }
    else
    {
        printf("Can't push any data in the stack.\n");
    }
    return ;
}

int pop( stack *s )
{
    if ( !isEmpty(s) )
    { 
        return s->arr[ (s->top)-- ];
    }
    else
    {
        printf("Can't pop any data from the stack.\n");
        return 0;
    }
}

void printStack( stack *s )
{
    if ( isEmpty(s) )
    {
        printf("Can't show any data.\n");
        return ;
    }

    // while ( ! isEmpty(s) )
    // {
        
    // }
    

    for ( int i = s->top; i >= 0; i-- )
    {
        printf("%d\t", s->arr[i]);
    }
    printf("\n");
    
}

int peek( stack *s, int pos )
{
    return s->arr[ pos ];
}

int inTop( stack *s )
{
    return s->arr[ s->top ];
}

int inBottom ( stack *s )
{
    return s->arr[ 0 ] ;
}