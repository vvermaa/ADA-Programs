#include <iostream>
using namespace std;

const int MAX = 20; // max number of vertices

int x[MAX];             // color assignment
int G[MAX][MAX];        // adjacency matrix
int n, m;               // n = number of vertices, m = number of colors

void nextval(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1); // try next color

        if (x[k] == 0) return; // no color found, backtrack

        int i;
        for (i = 1; i <= n; i++) {
            if (G[k][i] != 0 && x[i] == x[k])
                break; // conflict found
        }

        if (i == n + 1) return; // valid color found
    }
}

void mcolors(int k) {
    while (true) {
        nextval(k);

        if (x[k] == 0) return; // no valid color

        if (k == n) {
            // print solution
            cout << "Solution: ";
            for (int i = 1; i <= n; i++)
                cout << x[i] << " ";
            cout << endl;
        } else {
            mcolors(k + 1); // go to next vertex
        }
    }
}

int main() {
    // Sample graph (4 vertices)
    n = 4;
    m = 3;

    // Adjacency matrix (1-based index)
    G[1][2] = G[2][1] = 1;
    G[1][3] = G[3][1] = 1;
    G[1][4] = G[4][1] = 1;
    G[2][3] = G[3][2] = 1;
    G[3][4] = G[4][3] = 1;

    // Initialize color array
    for (int i = 1; i <= n; i++)
        x[i] = 0;

    cout << "M-Coloring solutions:\n";
    mcolors(1);

    return 0;
}
