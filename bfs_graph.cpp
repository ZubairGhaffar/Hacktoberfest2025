#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * BREADTH-FIRST SEARCH (BFS)
 * ----------------------------
 * Time Complexity: O(V + E)
 * V = number of vertices
 * E = number of edges
 *
 * BFS explores the graph level by level using a queue.
 * It ensures the shortest path (in unweighted graphs) from the source node.
 */

// Function to perform BFS traversal
void bfs(int startNode, vector<vector<int>>& adjList, int V) {
    vector<bool> visited(V, false); // Track visited nodes
    queue<int> q;                   // Queue for BFS

    // Start with the source node
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adjList(V);

    /*
     * Example Graph (Undirected)
     * 0 -- 1 -- 2
     * |    |    |
     * 3 -- 4 -- 5
     */
    adjList[0] = {1, 3};
    adjList[1] = {0, 2, 4};
    adjList[2] = {1, 5};
    adjList[3] = {0, 4};
    adjList[4] = {1, 3, 5};
    adjList[5] = {2, 4};

    bfs(0, adjList, V); // Start BFS from node 0

    return 0;
}
