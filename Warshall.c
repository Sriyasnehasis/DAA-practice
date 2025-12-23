#include <stdio.h>

#define MAX 10

int n;
int adj[MAX][MAX], T[MAX][MAX];
int topo[MAX], visited[MAX];

void warshall()
{
    // Copy adjacency matrix to T
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            T[i][j] = adj[i][j];

    // Compute transitive closure
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                T[i][j] = T[i][j] || (T[i][k] && T[k][j]);
}

void topoSort()
{
    int count = 0;

    while (count < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int incoming = 0;

                // Check if vertex i has no incoming edges
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && T[j][i])
                    {
                        incoming = 1;
                        break;
                    }
                }

                if (!incoming)
                {
                    topo[count++] = i;
                    visited[i] = 1;
                }
            }
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    warshall();
    topoSort();

    printf("\nTopological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", topo[i]);

    return 0;
}
