#include<stdio.h>
#include<limits.h>
#include<string.h>

#define N 1000

int graph[N][N];
int prev[N],d[N],color[N];


void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        printf("\nEnter relation between nodes:");
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;   

    }
    
}

void bfs(int start, int nodes){
    
    int queue[N];
    int front = 0, rear = 0;

    for (int i = 1; i <= nodes; i++) {//initialization
        color[i] = 0; // 0 represents white color
        prev[i] = 0;
        d[i] = INT_MAX;//infinity
    }

    d[start] = 0;
    color[start] = 1; // 1 represents gray color

    queue[rear++] = start;//gray holei push into queue

    while (front <= rear) {//jotokhon na queue empty hoche
        int u = queue[front++];//dequeue
        printf("%d ", u);//queue tai hoche bfs traversal
        for (int i = 1; i <= nodes; i++) {
            if (graph[u][i] == 1 && color[i] == 0){//u er shathe i er relation ache and i unvisited
                color[i] = 1; // Mark the adjacent node as gray
                d[i] = d[u] + 1;
                prev[i] = u;
                queue[rear++] = i;//jara gray hobe tara queue e dhukbe
            }
        }
        color[u] = 2; // Mark the current node as black if exploring finishes
    }
    
    printf("\nShortest distances from node %d:\n", start);
    for(int i = 1; i <= nodes; i++) {
        printf("Node %d: %d\n", i, d[i]);
    }
}

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    printf("Enter nodes and edges of the graph:");
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(start, nodes);

    return 0;
}