import sys

final_cost = sys.maxsize
final_path = []

def tsp(graph, visited, curr_cost, level, curr_path, n):
    global final_cost, final_path

    if level == n:
        if graph[curr_path[level - 1]][curr_path[0]] != 0:
            total_cost = curr_cost + graph[curr_path[level - 1]][curr_path[0]]

            if total_cost < final_cost:
                final_cost = total_cost
                final_path = curr_path[:] + [curr_path[0]]
        return

    for i in range(n):
        if graph[curr_path[level - 1]][i] != 0 and not visited[i]:
            temp_cost = curr_cost + graph[curr_path[level - 1]][i]

            if temp_cost < final_cost:  # Bounding condition
                visited[i] = True
                curr_path[level] = i

                tsp(graph, visited, temp_cost, level + 1, curr_path, n)

                visited[i] = False


# MAIN
n = int(input("Enter number of cities: "))

print("Enter cost matrix:")
graph = [list(map(int, input().split())) for _ in range(n)]

visited = [False] * n
visited[0] = True

curr_path = [-1] * n
curr_path[0] = 0

tsp(graph, visited, 0, 1, curr_path, n)

print("\nMinimum Cost:", final_cost)
print("Path:", *final_path)