#include<stdio.h>
#include<stdlib.h>
#include"STACK.h"

#define white 0
#define gray 1
#define black -1

#define size 20

int graph[size][size];
int trans[size][size];

int color[size];
int colTrans[size];

void transpose()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            trans[i][j]= graph[j][i];
        }
    }
}

void DFS_visit(int current, stack *s)
{
    color[current]= gray;

    for(int i=0; i<size; i++)
    {
        if(graph[current][i]==1 && color[i]== white)
        {
            DFS_visit(i, s); 
        }
    }
    color[current]= black;
    push(current, s);
}

void DFS(stack *s, int g[size][size])
{   
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(color[i]== white & g[i][j]== 1)   
            DFS_visit(i, s);
        }
    }

}

void printComponents(int node)
{
    printf("%d ", node);
    colTrans[node]= gray;

    for(int i=0; i<size; i++)
    {
        if(colTrans[i]== white && trans[node][i] == 1)   
            printComponents(i);
    }

    colTrans[node]= black;
}

void scc(int g[size][size])
{
    stack *s= createstack(size);
    DFS(s, g);
    transpose();

    printf("Strongly connected components:\n");

    while(!isempty(s))
    {
        int x= pop(s);
        if(colTrans[x] == white)
        {
            printComponents(x);
            printf("\n");
        }
    }
}

int main()
{
    int vertex, edge;
    
    printf("Enter the number of vertex and edges: ");
    scanf("%d %d", &vertex, &edge);
    printf("Enter the connections: ");
    
    for(int i=0; i<edge; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a][b]=1;
    }

   scc(graph);
}

/*
 1 2
 2 3
 3 4
 4 1
 3 5
 5 6
 6 7
 7 8
 8 6
*/