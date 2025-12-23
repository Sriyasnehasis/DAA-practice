# Prim's Algorithm in Python
import sys

def prims(graph):
    n = len(graph)
    selected = [False] * n
    selected[0] = True   # start from vertex 0
    edges = 0
    cost = 0

    print("Edge : Weight")
    while edges < n - 1:
        minimum = sys.maxsize
        x = y = 0
        for i in range(n):
            if selected[i]:
                for j in range(n):
                    if (not selected[j]) and graph[i][j] != 0:
                        if graph[i][j] < minimum:
                            minimum = graph[i][j]
                            x, y = i, j
        print(f"{x} - {y} : {graph[x][y]}")
        cost += graph[x][y]
        selected[y] = True
        edges += 1

    print("Total Cost of MST:", cost)

# Example Graph (Adjacency Matrix)
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

prims(graph)

