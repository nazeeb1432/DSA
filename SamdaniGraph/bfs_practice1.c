#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int graph[N][N],color[N],distance[N],prev[N],queue[N],front,rear;

#define white 0
#define grey 1
#define black 2

void create_graph(int nodes,int edges);

void BFS(int start,int nodes);

int main(){
    int nodes,edges,start;
    printf("Enter number of nodes and edges:");
    scanf("%d %d",&nodes,&edges);
    create_graph(nodes,edges);

    printf("Enter starting node:");
    scanf("%d",&start);
    BFS(start,nodes);

    printf("\nShortest distances from node %d:\n",start);
    for(int i=0;i<nodes;i++){
        printf("Node %d: %d\n",i,distance[i]);
    }

}

void create_graph(int nodes,int edges){
    int v1,v2;
    printf("Enter connections:\n");
    for(int i=0;i<edges;i++){
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
}
void BFS(int start,int nodes){
    //initialization
    for(int i=0;i<nodes;i++){
        color[i]=white;
        distance[i]=__INT_MAX__;
        prev[i]=__INT_MAX__;
    }
    distance[start]=0;
    color[start]=grey;
    queue[rear++]=start;//enqueue

    while(front<=rear){
        int u=queue[front++];
        printf("%d ",u);

        for(int i=0;i<nodes;i++){
            if(graph[u][i]==1 && color[i]==white){
                color[i]=grey;//visited kore dao jader shathe u er relation ase
                queue[rear++]=i;//grey hoilei insert into queue
                prev[i]=u;
                distance[i]=distance[u]+1;
            }
            color[u]=black;
        }
    } 

}