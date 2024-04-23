#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

int V;
int graph[MAX_VERTICES][MAX_VERTICES];

void show_colors(int color[])
{
    char color_name[] = {'R', 'G', 'B'};
    printf("Assigned colors are : ");
    for (int i = 0; i < V; i++)
    {
        printf("%c", color_name[color[i]]);
    }
    printf("\n");
}
bool is_valid(int v, int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
}
bool graph_coloring(int colors, int color[], int vertex)
{
    if (vertex == V)
    {
        show_colors(color);
        return true;
    }
    bool found_solution = false;
    for (int col = 0; col < colors; col++)
    {
        if (is_valid(vertex, color, col))
        {
            color[vertex] = col;
            found_solution = graph_coloring(colors, color, vertex + 1) || found_solution;
            color[vertex] = -1;
        }
    }
    return found_solution;
}
void check_solution(int m)
{
    int color[MAX_VERTICES];
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }
    if (!(graph_coloring(m, color, 0)))
    {
        printf("Solution does not exist");
    }
}

int main()
{
    printf("Enter the max number of vertices : ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix : \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int max_colors;
    printf("Enter the number of max colors : ");
    scanf("%d", &max_colors);
    if (max_colors > 3)
    {
        printf("Error!!");
    }
    else
    {
        check_solution(max_colors);
    }
    return 0;
}