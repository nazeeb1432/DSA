#include<bits/stdc++.h>
using namespace std;

struct Queue{

    int front,rear,capacity;
    int queue[];


    Queue(int c){
        front=rear=0;
        capacity=c;
    }

    //function to insert an elemnet
    //at the rear

    void queueEnqueue(int data){
        //check queue is full or not
        if(capacity==rear){
            printf("\nQueue is full");
        }

        //insert Element at the rear
        else{
            queue[rear]=data;
            rear++;
        }
    }

    //function to delete an element from the front of the queue
    void queueDequeue()
    {

        //if queue is empty
        if(front==rear){
            printf("\nQueue is empty\n");
        }

        //shift all the elements from index 1 till rear
        else{
            for(int i=0;i<rear-1;i++){
                queue[i]=queue[i+1];
            }
            //decrement rear
            rear--;
        }

    }
    //print queue elements
    void queueDisplay(){
        int i;
        if(front==rear){
            printf("\nQueue is empty\n");
            return;
        }
        for(i=front;i<rear;i++){
            printf("%d-->",queue[i]);
        }
        printf("\n");
        return;
    }

    //write a function to print the front of the queue

    void queueFront()
    {
        if(front==rear){
            printf("\nQueue is empty");          
        }
        printf("\nFront Element is:%d",queue[front]);


    }


};

int main(){

    //create a queue of capacity 4
    Queue q(40);

    //print queue elements
    q.queueDisplay();

    //inserting elements in the queue
    q.queueEnqueue(20);
    q.queueEnqueue(30);
    q.queueEnqueue(40);
    q.queueEnqueue(50);

    //print Queue elements
    q.queueDisplay();

    //insert element in the queue
    q.queueEnqueue(60);
    //print queue elements
    q.queueDisplay();
    
    q.queueDequeue();

    cout<<"Now the queue after dequeue:"<<endl;

    q.queueDisplay();
    








}



