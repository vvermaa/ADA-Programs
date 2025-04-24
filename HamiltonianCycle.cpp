#include <iostream>
using namespace std;

int G[10][10], x[10], n;

void nextval(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0) return;

        if (G[x[k - 1]][x[k]] != 0) {
            int i;
            for (i = 1; i < k; i++)
                if (x[i] == x[k]) break;

            if (i == k)
                if (k < n || (k == n && G[x[k]][x[1]] != 0))
                    return;
        }
    }
}

void ham(int k) {
    while (true) {
        nextval(k);
        if (x[k] == 0) return;

        if (k == n) {
            for (int i = 1; i <= n; i++) cout << x[i] << " ";
            cout << x[1] << endl;
        } else {
            ham(k + 1);
        }
    }
}

int main() {
    n = 4;
    int edges[5][2] = {{1,2},{2,3},{3,4},{4,1},{1,3}};

    for (int i = 0; i < 5; i++) {
        G[edges[i][0]][edges[i][1]] = 1;
        G[edges[i][1]][edges[i][0]] = 1;
    }

    x[1] = 1;
    ham(2);
    return 0;
}
