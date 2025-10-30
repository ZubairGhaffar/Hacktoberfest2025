#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * KRUSKAL'S MINIMUM SPANNING TREE ALGORITHM
 * ------------------------------------------
 * Time Complexity: O(E log E) due to edge sorting
 * E = number of edges
 * V = number of vertices
 *
 * The algorithm builds the MST by repeatedly adding the smallest edge 
 * that doesn't form a cycle, using the Disjoint Set Union (DSU) structure.
 */

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Compare edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (Union-Find) structure
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the representative of a set (with path compression)
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union two sets (by rank)
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false; // already connected
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Function to compute Kruskal’s MST
void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges); // Step 1: Sort edges by weight

    DSU dsu(V);
    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (auto& edge : edges) {
        // Step 2: Pick the smallest edge that doesn’t form a cycle
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            mstEdges.push_back(edge);
        }
    }

    // Step 3: Print the result
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& edge : mstEdges)
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;

    cout << "Total Weight of MST = " << mstWeight << endl;
}

// Main function
int main() {
    int V = 6; // Number of vertices

    // Define graph edges (u, v, weight)
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2},
        {1, 0, 4}, {2, 0, 4}, {2, 3, 3},
        {2, 5, 2}, {2, 4, 4}, {3, 4, 3},
        {5, 4, 3}
    };

    kruskalMST(V, edges);
    return 0;
}
