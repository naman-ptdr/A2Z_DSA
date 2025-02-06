// Here is a C++ program to find and traverse connected components in an undirected graph using DFS (Depth-First Search) and BFS (Breadth-First Search):

// Approach:
// Adjacency list representation of the graph.
// Visited array to track visited nodes.
// DFS/BFS traversal to explore connected components.
// Loop through all nodes to find separate components.


#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<bool> visited;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    void DFS(int node) {
        cout << node << " ";
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor);
            }
        }
    }

    void BFS(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void findConnectedComponents() {
        fill(visited.begin(), visited.end(), false); // Reset visited array
        int count = 0;
        cout << "Connected Components (using DFS):\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                cout << "Component " << count << ": ";
                DFS(i);
                cout << endl;
            }
        }

        // Reset visited array for BFS
        fill(visited.begin(), visited.end(), false);
        count = 0;
        cout << "\nConnected Components (using BFS):\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                cout << "Component " << count << ": ";
                BFS(i);
                cout << endl;
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    Graph g(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findConnectedComponents();
    
    return 0;
}
