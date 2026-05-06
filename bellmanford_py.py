V, E = map(int, input("Enter vertices and edges: ").split())

edges = []
print("Enter edges (u v weight):")
for _ in range(E):
    u, v, w = map(int, input().split())
    edges.append((u, v, w))

source = int(input("Enter source vertex: "))

INF = float('inf')
dist = [INF] * V
parent = [-1] * V

dist[source] = 0

# Relax edges V-1 times
for _ in range(V - 1):
    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            parent[v] = u

# Check negative cycle
for u, v, w in edges:
    if dist[u] != INF and dist[u] + w < dist[v]:
        print("Graph contains negative weight cycle")
        exit()

# Print paths
print("\nVertex\tCost\tPath")
for i in range(V):
    print(i, "\t", dist[i], "\t", end="")

    path = []
    v = i
    while v != -1:
        path.append(v)
        v = parent[v]

    print(*reversed(path))