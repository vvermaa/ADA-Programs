#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findStages(int n, vector<vector<int>> &graph) // Function to find the number of stages in a multistage graph
{   vector<int> stage(n, -1);
    int stageCount = 1;
    stage[n - 1] = stageCount; // Last node belongs to last stage
    // Traverse nodes from right to left
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0 && stage[j] != -1) {
                stage[i] = stage[j] + 1;
                break;
            }
        }
    }
    return stage[0]; // Return the number of stages
}
int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (enter 0 for no edge):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Number of stages in the multistage graph: " << findStages(n, graph) << endl;
    return 0;
}
