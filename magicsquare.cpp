#include <iostream>
#include <vector>
using namespace std;
void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;
        int new_i = (i - 1 + n) % n;
        int new_j = (j - 1 + n) % n;
        if (magicSquare[new_i][new_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }
    // Print the magic square
    cout << "Magic Square of size " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter the size of the Magic Square (odd number): ";
    cin >> n;
    if (n % 2 == 0 || n < 1) {
        cout << "Size must be an odd number greater than 0." << endl;
        return 1;
    }
    generateMagicSquare(n);
    return 0;
}
