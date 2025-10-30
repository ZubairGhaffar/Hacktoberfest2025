#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

/*
 * DIJKSTRA'S SHORTEST PATH ALGORITHM
 * -----------------------------------
 * Time Complexity: O(V + E log V)
 * V = number of vertices
 * E = number of edges
 * 
 * The algorithm finds the shortest path from a single source to all other nodes
 * in a weighted graph (non-negative weights).
 */

// Function to implement Dijkstra’s algorithm
void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int source) {
    // Create a min-heap priority queue (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance vector initialized with infinity
    vector<int> dist(V, numeric_limits<int>::max());

    // Distance to source is always 0
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // Skip if this distance is not the latest shortest
        if (currentDist > dist[currentNode])
            continue;

        // Explore neighbors
        for (auto& neighbor : adj[currentNode]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            // Relaxation step
            if (currentDist + edgeWeight < dist[nextNode]) {
                dist[nextNode] = currentDist + edgeWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tShortest Distance from Source (" << source << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

// Main function
int main() {
    int V = 5; // Number of vertices

    // Adjacency list representation: adj[node] = { (neighbor, weight), ... }
    vector<vector<pair<int, int>>> adj(V);

    // Graph edges (u, v, weight)
    adj[0].push_back({1, 9});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[0].push_back({4, 3});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 4});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}
