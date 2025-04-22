#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to merge and remove dominated states
vector<pair<int, int>> MergePurge(vector<pair<int, int>> S1, vector<pair<int, int>> S2) {
    vector<pair<int, int>> merged = S1;
    
    // Insert new elements from S2
    for (auto state : S2) {
        merged.push_back(state);
    }

    // Sort by weight first, then by profit (descending)
    sort(merged.begin(), merged.end());

    // Purge dominated states
    vector<pair<int, int>> cleaned;
    int maxProfit = -1;
    for (int i = merged.size() - 1; i >= 0; i--) {
        if (merged[i].first > maxProfit) {
            cleaned.push_back(merged[i]);
            maxProfit = merged[i].first;
        }
    }

    return cleaned;
}

// Knapsack Problem Solution
vector<pair<int, int>> KSP(int n, int p[], int w[], int W) {
    vector<pair<int, int>> S[n + 1];
    S[0].push_back({0, 0});

    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> newStates;
        
        // Generate new states
        for (auto state : S[i - 1]) {
            int newProfit = state.first + p[i - 1];
            int newWeight = state.second + w[i - 1];

            if (newWeight <= W) {
                newStates.push_back({newProfit, newWeight});
            }
        }

        // Merge and Purge
        S[i] = MergePurge(S[i - 1], newStates);
    }

    return S[n];
}

// Traceback function to determine selected items
void TraceBack(int p[], int w[], int n, int W, vector<pair<int, int>> S) {
    int PX = 0, WX = 0;
    
    // Find the best (profit, weight) pair within weight limit
    for (auto state : S) {
        if (state.second <= W && state.first > PX) {
            PX = state.first;
            WX = state.second;
        }
    }

    // Array to store selected items
    int X[n] = {0};

    // Backtracking to find selected items
    for (int i = n; i > 0; i--) {
        for (auto state : S) {
            if (state.first == PX && state.second == WX) {
                X[i - 1] = 1;
                PX -= p[i - 1];
                WX -= w[i - 1];
                break;
            }
        }
    }

    // Print selected items
    cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        if (X[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 4, W = 10;
    int p[] = {10, 40, 30, 50};  // Profits
    int w[] = {5, 4, 6, 3};      // Weights

    vector<pair<int, int>> S = KSP(n, p, w, W);

    // Find and display the optimal profit
    int maxProfit = 0;
    for (auto state : S) {
        if (state.second <= W) {
            maxProfit = max(maxProfit, state.first);
        }
    }
    cout << "Optimal Profit: " << maxProfit << endl;

    // Traceback to find the selected items
    TraceBack(p, w, n, W, S);

    return 0;
}
