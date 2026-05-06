#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int final_cost = INT_MAX;
vector<int> final_path;

void tsp(vector<vector<int>>& graph, vector<bool>& visited,
         int curr_bound, int curr_cost, int level,
         vector<int>& curr_path) {

    // If all cities are visited
    if (level == N) {
        if (graph[curr_path[level - 1]][curr_path[0]] != 0) {
            int total_cost = curr_cost +
                             graph[curr_path[level - 1]][curr_path[0]];

            if (total_cost < final_cost) {
                final_path = curr_path;
                final_path.push_back(curr_path[0]);
                final_cost = total_cost;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (graph[curr_path[level - 1]][i] != 0 && !visited[i]) {
            int temp_bound = curr_bound;
            int temp_cost = curr_cost + graph[curr_path[level - 1]][i];

            // Bound check (simple)
            if (temp_cost < final_cost) {
                curr_path[level] = i;
                visited[i] = true;

                tsp(graph, visited, temp_bound,
                    temp_cost, level + 1, curr_path);

                visited[i] = false;
            }
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    vector<bool> visited(N, false);
    vector<int> curr_path(N);

    visited[0] = true;
    curr_path[0] = 0;

    tsp(graph, visited, 0, 0, 1, curr_path);

    cout << "\nMinimum Cost: " << final_cost << endl;
    cout << "Path: ";
    for (int i : final_path)
        cout << i << " ";
    cout << endl;

    return 0;
}