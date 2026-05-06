#include <iostream>
#include <vector>
using namespace std;

bool hamiltonianPath(vector<vector<int>>& graph, int N) {
    vector<int> path(N, -1);
    vector<bool> visited(N, false);
    vector<int> next(N, 0); // track next vertex to try

    path[0] = 0; // start from vertex 0
    visited[0] = true;

    int pos = 1;

    while (pos >= 0) {
        if (pos == N) {
            // Found solution
            cout << "Hamiltonian Path: ";
            for (int i = 0; i < N; i++)
                cout << path[i] << " ";
            cout << endl;
            return true;
        }

        bool found = false;

        for (int v = next[pos]; v < N; v++) {
            int prev = path[pos - 1];

            if (graph[prev][v] == 1 && !visited[v]) {
                path[pos] = v;
                visited[v] = true;
                next[pos] = v + 1; // next time start from next vertex

                pos++;
                if (pos < N) next[pos] = 0;

                found = true;
                break;
            }
        }

        if (!found) {
            // Backtrack
            next[pos] = 0;
            pos--;

            if (pos >= 0) {
                visited[path[pos]] = false;
            }
        }
    }

    cout << "No Hamiltonian Path exists\n";
    return false;
}

int main() {
    int N;
    cout << "Enter number of vertices: ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    hamiltonianPath(graph, N);

    return 0;
}