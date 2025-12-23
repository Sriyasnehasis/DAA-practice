#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Edge
{
    int u, v, w;
};

// Disjoint Set (Union-Find)
int parent[MAX], rankArr[MAX];

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]); // Path compression
    return parent[x];
}

int unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB)
        return 0;

    // Union by rank
    if (rankArr[rootA] < rankArr[rootB])
        parent[rootA] = rootB;
    else if (rankArr[rootA] > rankArr[rootB])
        parent[rootB] = rootA;
    else
    {
        parent[rootB] = rootA;
        rankArr[rootA]++;
    }
    return 1;
}

// Compare edges for sorting
int cmp(const void *a, const void *b)
{
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

int main()
{
    int n, e;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Sort edges by weight
    qsort(edges, e, sizeof(struct Edge), cmp);

    makeSet(n);

    int mstWeight = 0;
    printf("\nEdges in MST:\n");

    for (int i = 0; i < e; i++)
    {
        if (unionSet(edges[i].u, edges[i].v))
        {
            printf("%d -- %d  == %d\n", edges[i].u, edges[i].v, edges[i].w);
            mstWeight += edges[i].w;
        }
    }

    printf("\nTotal weight of MST: %d\n", mstWeight);

    return 0;
}
