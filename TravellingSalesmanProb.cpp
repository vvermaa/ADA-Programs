#include <iostream>
#include <climits>
using namespace std;

int tsp(int graph[4][4], bool visited[], int pos, int n, int count, int cost, int start, int path[], int& minCost, int bestPath[]) {
    if (count == n && graph[pos][start] > 0) {
        // Complete the cycle
        cost += graph[pos][start];
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i]; // Store the best path
            }
        }
        return cost;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i] > 0) {
            visited[i] = true;
            path[count] = i;
            ans = min(ans, tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start, path, minCost, bestPath));
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int n = 4;
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    bool visited[4] = {false};
    int path[4], bestPath[4];
    int minCost = INT_MAX;
    
    visited[0] = true;
    path[0] = 0;

    int cost = tsp(graph, visited, 0, n, 1, 0, 0, path, minCost, bestPath);

    cout << "Minimum cost of TSP: " << minCost << endl;
    cout << "Path taken: ";
    for (int i = 0; i < n; i++) {
        cout << bestPath[i] << " ";
    }
    cout << endl;

    return 0;
}
