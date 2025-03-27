#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half)), A12(half, vector<int>(half)),
                        A21(half, vector<int>(half)), A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half)), B12(half, vector<int>(half)),
                        B21(half, vector<int>(half)), B22(half, vector<int>(half));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j]; A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j]; A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j]; B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j]; B22[i][j] = B[i + half][j + half];
        }                                                           
    }
    vector<vector<int>> C11 = addMatrix(multiplyMatrix(A11, B11), multiplyMatrix(A12, B21));
    vector<vector<int>> C12 = addMatrix(multiplyMatrix(A11, B12), multiplyMatrix(A12, B22));
    vector<vector<int>> C21 = addMatrix(multiplyMatrix(A21, B11), multiplyMatrix(A22, B21));
    vector<vector<int>> C22 = addMatrix(multiplyMatrix(A21, B12), multiplyMatrix(A22, B22));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j]; C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j]; C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}
void displayMatrix(const vector<vector<int>>& C) {
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter matrix size (power of 2): ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
        
    }
    cout << "Resultant Matrix:\n";
    displayMatrix(multiplyMatrix(A, B));
    return 0;
}