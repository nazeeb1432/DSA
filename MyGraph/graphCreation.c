#include<stdio.h>
#include<string.h>
#include<stdlib.h>

# define N 100
int graph[N][N];

void create_graph(int nodes,int edges){
    int u,v;//u and v are adjacent vertices
    //now create the relation matrix,jotogula edge totogula relation
    for(int i=1;i<=edges;i++){
        printf("\nEnter adjacent vertices:");
        scanf("%d %d",&u,&v);
        graph[u][v] =1;
        graph[v][u] =1;
    }
}
void print_graph(int nodes){
    printf("\n the adjacent matrix of the graph:\n");
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){

            printf("%d ",graph[i][j]);

        }printf("\n");
    }
}

int main(){

    int nodes,edges;
    printf("Enter no. of nodes and edges:");
    scanf("%d %d",&nodes,&edges);

    create_graph(nodes,edges);
    print_graph(nodes);

    

    return 0;
}