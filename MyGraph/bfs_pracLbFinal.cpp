#include <bits/stdc++.h>
using namespace std;

#define max 20
string countries[max];
int graph[max][max], d[max];
int q[max], f = -1, r = -1;

void enqueue(int value)
{
    if (r == max)
    {
        cout << "Overflow\n"
             << endl;
        return;
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        q[r] = value;
    }
    else
        q[r++] = value;
}

int dequeue()
{
    if (f > r || f == -1)
    {
        cout << "underflow\n";
        return -1;
    }
    return q[f++];
}

void create_graph(int x, int y)
{
    graph[x][y] = 1;
    graph[y][x] = 1;
}

void bfs(int start, int v)
{
    int i;
    int visited[20]={0};
    
    visited[start] = 1;
    enqueue(start);
    d[start] = 0;

    cout << "You can travel from " << countries[start] << " to"<< ":" << endl;
         

    while (f <= r)
    {
        int temp = dequeue();
        if (temp != start)
            cout << countries[temp] << endl;
        for (int i = 0; i < v; i++)
        {
            if (graph[temp][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
                d[i] = d[start] + 1;
            }
        }
    }
}

void adjacentCountries(int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Adjacent of country " << countries[i] << ":";
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j])
            {
                cout << countries[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void shortest_path(int start, int v)
{
    cout << "shortest distances from " << countries[start] << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "country " << countries[i] << ":" << d[i] << endl;
    }
}

int main()
{
    int v, e, x, y, start;
    string a, b;
    cout << "Enter number of countries:";
    cin >> v;
    cout << "Enter the countries:" << endl;
    for (int i = 0; i < v; i++)
    {
        cin >> countries[i];
    }
    cout << "Enter number of edges:";
    cin >> e;
    cout << "Enter connections:\n";
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;

        for (int j = 0; j < v; j++)
        {
            if (a == countries[j])
                x = j;
            if (b == countries[j])
                y = j;
        }
        create_graph(x, y);
    }

    cout << "Enter starting country:";
    cin >> a;
    for (int i = 0; i < v; i++)
    {
        if (a == countries[i])
        {
            start = i;
            break;
        }
    }

    bfs(start, v);

    // adjacentCountries(v);
    // shortest_path(start,v);
}
