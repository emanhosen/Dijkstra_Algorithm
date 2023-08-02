#include<stdio.h>
#include<stdlib.h>

int V = 5;


int minDistance(int dist[10], int sptSet[10])
{
    int min = 99, min_index = -1, i;

    for (i = 0; i < V; i++)
    {
        if(sptSet[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;

}

void printSolution(int dist[10])
{

    printf("Vertex \t\t Distance from Source\n");
    int i;
    for (i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }

}


void dijkstra(int graph[5][5], int src)
{

    int dist[10];
    int sptSet[10];
    int i,u,v,count;

    for (i = 0; i < V; i++)
    {
        dist[i] = 99;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < V-1; count++)
    {
        u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != 99 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);

}

void main()
{
    int graph[5][5] = {{0,10,5,0,0},
        {0,0,2,1,0},
        {0,3,0,9,2},
        {0,0,0,0,4},
        {7,0,0,6,0}
    };

    dijkstra(graph, 0);
}
