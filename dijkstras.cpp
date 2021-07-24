#include <limits.h>
#include <stdio.h>

#define V 9

int minDistance(int dis[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dis[v] <= min)
            min = dis[v], min_index = v;

    return min_index;
}

void print(int dis[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dis[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dis[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX, sptSet[i] = false;

    dis[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dis, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dis[u] != INT_MAX && dis[u] + graph[u][v] < dis[v])
                dis[v] = dis[u] + graph[u][v];
    }

    print(dis);
}

int main()
{

    int graph[V][V] = {{0, 12, 0, 0, 0, 0, 0, 8, 0},
                       {3, 0, 9, 0, 0, 0, 0, 10, 0},
                       {0, 1, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 16, 0, 0, 0},
                       {0, 0, 0, 9, 0, 11, 0, 0, 0},
                       {0, 0, 4, 3, 21, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 8},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 1, 0, 0, 0, 6, 5, 0}};

    dijkstra(graph, 0);

    return 0;
}
