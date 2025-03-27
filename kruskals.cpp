#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};
// Disjoint Set Union (DSU) - Find with Path Compression
int find(int x, vector<int>& parent) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x], parent);
}
// DSU - Union by rank
void unionSets(int x, int y, vector<int>& parent) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX != rootY) parent[rootX] = rootY;
}
// Kruskal's Algorithm
void ka(vector<Edge>& edges, int n, vector<pair<int, int>>& t) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap(edges.begin(), edges.end());
    vector<int> parent(n, -1);
    int i = 0;
    while (i < n - 1 && !minHeap.empty()) {
        Edge e = minHeap.top();
        minHeap.pop();
        int u = e.u, v = e.v;
        int j = find(u, parent), k = find(v, parent);
        if (j != k) {
            i++;
            t.push_back({u, v});
            unionSets(j, k, parent);
        }
    }
    if (i != n - 1) cout << "No spanning tree\n";
    else {
        cout << "Spanning Tree:\n";
        for (size_t idx = 0; idx < t.size(); ++idx) {
            cout << t[idx].first << " - " << t[idx].second << endl;
        }
    }
}
// Main function
int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };   
    vector<pair<int, int>> t;
    ka(edges, n, t);
    return 0;
}
