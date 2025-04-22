#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char X[100], Y[100];

    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = strlen(X);
    int n = strlen(Y);

    int dp[101][101]; // To store lengths of LCS

    // Fill the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // Base case
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // If not match
        }
    }

    // Length of LCS is at dp[m][n]
    cout << "Length of Longest Common Subsequence: " << dp[m][n] << endl;

    // To print LCS
    int index = dp[m][n];
    char lcs[101]; // To store the LCS string
    lcs[index] = '\0'; // Null terminate

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
