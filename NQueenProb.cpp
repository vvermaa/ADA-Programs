#include <iostream>
#include <cmath>
using namespace std;

int x[20]; // x[k] = i means k-th queen is placed in row i
int n;

bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false; // Same row or same diagonal
        }
    }
    return true;
}

void printSolution() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void nqueens(int k) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n)
                printSolution();
            else
                nqueens(k + 1);
        }
    }
}

int main() {
    cout << "Enter number of queens (N): ";
    cin >> n;
    nqueens(1); // Start placing from the first queen
    return 0;
}
