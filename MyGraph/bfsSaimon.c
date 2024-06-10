#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int vertex,edge;

struct queue{
    int *arr;
    int size;
    int f,r;
};

void enqueue(struct queue* q,int data);
int dequeue(struct queue* q);
int isfull(struct queue* q);
int isEmpty(struct queue* q);

struct queue* createQueue(){

    struct queue* q =malloc(sizeof(struct queue));
    q->f=-1;
    q->r=-1;
    q->arr=malloc(q->size* sizeof(int));
    return q;
}

int isEmpty(struct queue *q){
    if(q->f==q->r) return 1;
    else return 0;
}

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else return 0;
}

void enqueue(struct queue *q,int data){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r]=data;
    }
}

int dequeue(struct queue *q){
    int val;
    if(!isEmpty(q)){
        val=q->arr[q->f];
        q->f++;
    }
    return val;
}

#define WHITE 0
#define Black -1
#define GRAY 1

int graph[27][27];//matrix
int level[27];//distance of sir slide
bool visited[27];//color of the sumon sir slide

void BFS(char source){
    struct queue *q =createQueue();
    enqueue(q,source-'a');//source character ke integer e convert korar jonno.
    visited[source-'a']=true;
    level[source-'a']=0;//level and distance same shit
    while(!isEmpty(q)){
        int cur_v=dequeue(q);
        for(int i=0;i<vertex;i++){
            if(graph[cur_v][i]==1 && visited[i]==false){//color[i]=white
                visited[i]=true;
                level[i]=level[cur_v]+1;
                enqueue(q,i);//jader color gray or jara visited hobe taderke queue e dhukaite hobe.
            }
        }
    }
    
}



int main(){

    //vertex and edge globally declared
    printf("Enter vertex and edge numbers:\n");
    scanf("%d %d",&vertex,&edge);
    getchar();
    for(int i=0;i<edge;i++){
        char a,b;
        scanf("%c %c",&a,&b);
        getchar();
        graph[a-'a'][b-'a'] =1;
        graph[b-'a'][a-'a'] =1;
    }
    BFS('a');//starting charactere a;
    for(int i=0;i<vertex;++i){
        if(level[i]!=0)//to ignore the source node
        {
            printf("distance of %c from %c is %d\n",i+'a','a',level[i]);
        }
    }
    

    return 0;
}