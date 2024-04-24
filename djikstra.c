#include <stdio.h>
#define infinity 9999

int v;

int min_distance(int d[v], int s[v])
{
    int minimum = infinity, index = -1;
    for (int i = 0; i < v; i++)
    {
        if (s[i] == 0 && d[i] <= minimum)
        {
            minimum = d[i];
            index = i;
        }
    }
    return index;
}

void print_path(int p[], int i)
{ 
    if (p[i] == -1)
    {
        return;
    };
    print_path(p, p[i]);
    printf("%c ", i + 65);
}

void print_solution(int d[v], int p[v], int source)
{
    for (int i = 1; i < v; i++)
    {
        printf("%c -> %c | %d | %c ", source + 65, i + 65, d[i], source + 65);
        print_path(p, i);
        printf("\n");
    }
}

void dijkstra(int graph[v][v], int source)
{
    int d[v], p[v], s[v];
    for (int i = 0; i < v; i++)
    {
        d[i] = infinity;
        p[i] = -1;
        s[i] = 0;
    }
    d[source] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int u = min_distance(d, s);
        s[u] = 1;
        for (int j = 0; j < v; j++)
        {
            if (s[j] == 0 && graph[u][j] && d[u] != infinity && d[u] + graph[u][j] < d[j])
            {
                d[j] = d[u] + graph[u][j];
                p[j] = u;
            }
        }
    }
    print_solution(d, p, source);
}

void main()
{
    printf("enter number of vertices: ");
    scanf("%d", &v);
    int graph[v][v], source;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            scanf("%d", &graph[i][j]);
    printf("enter source vertex: ");
    scanf("%d", &source);
    dijkstra(graph, source);
}
