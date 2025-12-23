from collections import deque

def bfs(graph, start):
    visited = [False] * len(graph)   # keep track of visited nodes
    queue = deque([start])           # initialize queue
    visited[start] = True

    print("BFS Traversal starting from node", start, ":")
    while queue:
        node = queue.popleft()
        print(node, end=" ")

        # check all adjacent vertices
        for i in range(len(graph[node])):
            if graph[node][i] == 1 and not visited[i]:
                queue.append(i)
                visited[i] = True


# Example graph (Adjacency Matrix)
graph = [
    [0, 1, 1, 0, 0],  # Node 0 connected to 1 and 2
    [1, 0, 0, 1, 0],  # Node 1 connected to 0 and 3
    [1, 0, 0, 1, 1],  # Node 2 connected to 0, 3, 4
    [0, 1, 1, 0, 0],  # Node 3 connected to 1 and 2
    [0, 0, 1, 0, 0]   # Node 4 connected to 2
]

# Perform BFS
bfs(graph, 0)


