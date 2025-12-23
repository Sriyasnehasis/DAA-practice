# Depth First Search (DFS) using Python

def dfs(graph, visited, node):
    if node not in visited:
        print(node, end=" ")       # visit the node
        visited.add(node)          # mark as visited
        for neighbour in graph[node]:
            dfs(graph, visited, neighbour)


# Driver Code
if __name__ == "__main__":
    # Graph represented as adjacency list (dictionary)
    graph = {
        0: [1, 2],
        1: [0, 3, 4],
        2: [0, 5],
        3: [1],
        4: [1, 5],
        5: [2, 4]
    }

    visited = set()
    source = 0   # starting vertex
    print("DFS Traversal starting from vertex", source, ":")
    dfs(graph, visited, source)









