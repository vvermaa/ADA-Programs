#include <iostream>
using namespace std;
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];  // The maximum value that can be carried
}
int main() {
    int val[] = {60, 100, 120};  // Values of items
    int wt[] = {10, 20, 30};     // Weights of items
    int W = 50;                  // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);  // Number of items
    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}
