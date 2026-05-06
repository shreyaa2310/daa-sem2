#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[source] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check negative cycle
    for(int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return 0;
        }
    }

    // Print paths
    cout << "\nVertex\tCost\tPath\n";
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t";

        // Print path
        vector<int> path;
        for(int v = i; v != -1; v = parent[v])
            path.push_back(v);

        for(int k = path.size() - 1; k >= 0; k--)
            cout << path[k] << " ";

        cout << endl;
    }

    return 0;
}