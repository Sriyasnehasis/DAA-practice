INF = 10**9

def floyd_warshall(graph):
    n = len(graph)
    # make a copy so input isn't modified
    dist = [row[:] for row in graph]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

def print_matrix(mat):
    for row in mat:
        print(" ".join("INF" if x >= INF//2 else str(x) for x in row))

# Example graph (use INF for no direct edge)
graph = [
    [0,   5,  INF, 10],
    [INF, 0,   3,  INF],
    [INF, INF, 0,   1],
    [INF, INF, INF, 0]
]

result = floyd_warshall(graph)
print("Shortest distances between every pair of vertices:")
print_matrix(result)
