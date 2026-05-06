def hamiltonian_path(graph, n):
    path = [-1] * n
    visited = [False] * n
    next_choice = [0] * n

    path[0] = 0
    visited[0] = True

    pos = 1

    while pos >= 0:
        if pos == n:
            print("Hamiltonian Path:", *path)
            return True

        found = False

        for v in range(next_choice[pos], n):
            prev = path[pos - 1]

            if graph[prev][v] == 1 and not visited[v]:
                path[pos] = v
                visited[v] = True
                next_choice[pos] = v + 1

                pos += 1
                if pos < n:
                    next_choice[pos] = 0

                found = True
                break

        if not found:
            next_choice[pos] = 0
            pos -= 1

            if pos >= 0:
                visited[path[pos]] = False

    print("No Hamiltonian Path exists")
    return False


# MAIN
n = int(input("Enter number of vertices: "))

print("Enter adjacency matrix:")
graph = [list(map(int, input().split())) for _ in range(n)]

hamiltonian_path(graph, n)