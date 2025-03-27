# include <iostream>
# include <vector>
# include <limits.h>
using namespace std;
void MGP(vector<vector<int>>& cost, int n, int k) {
    vector<int> fdist(n + 1, INT_MAX);
    vector<int> d(n + 1, -1);
    fdist[n] = 0;
    for (int j = n - 1; j >= 1; j--) {
        for (int r = j + 1; r <= n; r++) {
            if (cost[j][r] != 0 && cost[j][r] + fdist[r] < fdist[j]) {
                fdist[j] = cost[j][r] + fdist[r];
                d[j] = r;
            }
        }
    }
    vector<int> fpath(k + 1);
    fpath[1] = 1;
    fpath[k] = n;
    for (int j = 2; j < k; j++) {
        fpath[j] = d[fpath[j - 1]];
    }
    cout << "Minimum cost: " << fdist[1] << endl;
    cout << "Path: ";
    for (int j = 1; j <= k; j++) {
        cout << fpath[j] << " ";
    }
    cout << endl;
}
int main() {
    int n, k;
    cout << "Enter number of vertices and stages: ";
    cin >> n >> k;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
    cout << "Enter cost matrix (use 0 for no direct path):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }
    MGP(cost, n, k);
    return 0;
}
