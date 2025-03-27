#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF 99 // Representing infinity
// Function to compute APSP using Floyd-Warshall Algorithm
void APSP(vector<vector<int>>& cost, int n, vector<vector<int>>& next) {
    vector<vector<int>> a = cost; // Copy the cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != INF && i != j)
                next[i][j] = j;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] != INF && a[k][j] != INF && a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    // Print shortest paths
    cout << "All-Pairs Shortest Paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "Shortest path from " << i + 1 << " to " << j + 1 << ": ";
                if (a[i][j] == INF) {
                    cout << "No path" << endl;
                } else {
                    int u = i;
                    cout << u + 1;
                    while (u != j) {
                        u = next[u][j];
                        cout << " -> " << u + 1;
                    }
                    cout << " (Cost: " << a[i][j] << ")" << endl;
                }
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> next(n, vector<int>(n, -1));
    cout << "Enter the adjacency matrix (use " << INF << " for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    
    APSP(cost, n, next);
    return 0;
}
