#include <stdio.h>
int graph[20][20], discovery[20], finish[20], previous[20], time, color[20], stack[20], top;
void push(int value); // finish time,discovery time
int pop();
void dfs(int vertice);
void dfs_visit(int vertice, int source);

#define White 0 // white unvisited
#define Grey 1  // grey visited
#define Black 2 // black visited and finished




int main()
{
    int v1, v2, i, j, vertice, edge;
    printf("Enter number of vertices and edges:");
    scanf("%d %d", &vertice, &edge);
    // now create the graph
    for (i = 0; i < edge; i++)
    {
        printf("enter vertices of edge %d:", i + 1);
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
    }
    // now call the dfs function
    dfs(vertice);
    printf("vertice\t\tdiscovery\tfinish\n");
    for (i = 0; i < vertice; i++)
    {
        printf("%d\t\t%d\t\t%d\n", i, discovery[i], finish[i]);
    }
    printf("\nTopological sort\n");
    for (i = 0; i < vertice; i++)
    {
        printf("%d\t", pop());
    }

    return 0;
}

void push(int value)
{
    stack[top++] = value;
}
int pop()
{
    return stack[--top];
}

void dfs(int vertice)
{
    int i;
    // ei function er first kaj holo initialization of the vertices
    for (i = 0; i < vertice; i++)
    {                            // 0 represents first vertex
        previous[i] = -1;        // 1 represents second vertex;
        finish[i] = __INT_MAX__; // 2 represents third vertex;
        discovery[i] = __INT_MAX__;
    }
    for (i = 0; i < vertice; i++)
    {                                // prottekta vertex ke visit korbo;
        if (color[i] == White)
        {                          // for forest ,i=1,2,3,4,5 er jonno color black pabe,for i=6(f) er jonno dhukbe
            dfs_visit(vertice, i); // vertice is total vertice number. I represents vertex
        }
    }
}

void dfs_visit(int vertice, int source)
{
    int i;
    color[source] = Grey;
    discovery[source] = ++time;
    for (i = 0; i < vertice; i++)
    {
        if (graph[source][i] == 1 && color[i] == White)
        {
            previous[i] = source;
            dfs_visit(vertice, i);
        }
    }
    color[source] = Black;
    finish[source] = ++time;
    push(source); // for topological sort,black hoilei insert into stack
}
