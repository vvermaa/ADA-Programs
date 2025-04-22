#include <iostream>
#include <limits.h>
using namespace std;
#define INFINITY INT_MAX  // Use INT_MAX instead of 99999999

// Function to compute the Matrix Chain Multiplication
void NSMM(int p[], int n, int s[][100], int m[][100]) {
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;  // Diagonal elements are zero
    }

    for (int l = 2; l < n; l++) { // l is the chain length
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INFINITY;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][100], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int p[] = {10,20,5,10,30};
    int n = sizeof(p) / sizeof(p[0]);

    int s[100][100] = {0};  // Stores optimal split points
    int m[100][100] = {0};  // Stores minimum multiplication cost

    NSMM(p, n, s, m);

    cout << "Minimum number of scalar multiplications is " << m[1][n - 1] << endl;
    cout << "Optimal Parenthesization is ";
    printOptimalParenthesis(s, 1, n - 1);
    cout << endl;

    return 0;
}
