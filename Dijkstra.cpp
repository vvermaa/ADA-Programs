#include <iostream>
#include <climits>
using namespace std;

#define V 5 // Number of vertices

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] < min)
            min = dist[v], minIndex = v;
    return minIndex;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Stores shortest distance from source to each vertex
    bool visited[V]; // True if vertex is finalized

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t" << dist[i] << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
