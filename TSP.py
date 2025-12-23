import numpy as np
def tsp_nearest_neighbor(distance_matrix, start=0):
    n = len(distance_matrix)
    visited = [False] * n
    tour = [start]
    visited[start] = True
    total_distance = 0
    current = start
    for _ in range(n - 1):
        nearest = None
        min_dist = float('inf')
        for city in range(n):
            if not visited[city] and distance_matrix[current][city] < min_dist:
                nearest = city
                min_dist = distance_matrix[current][city]
        tour.append(nearest)
        visited[nearest] = True
        total_distance += min_dist
        current = nearest

    total_distance += distance_matrix[current][start]  # return to start
    tour.append(start)
    return tour, total_distance

# Example distance matrix
dist = np.array([
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
])

path, cost = tsp_nearest_neighbor(dist, start=0)
print("Nearest Neighbor Path:", path)
print("Total Distance:", cost)



