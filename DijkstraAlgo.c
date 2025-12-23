#include <stdio.h>
#define INF 9999
#define MAX 10

int n;
int cost[MAX][MAX];

int minDistance(int dist[], int visited[])
{
    int min = INF, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int start)
{
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != 0 && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
        }
    }

    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int start;
    printf("Enter source vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}
