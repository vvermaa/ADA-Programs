#include <iostream>
#include <vector>
using namespace std;
int findMaxIndex(vector<vector<int>> &matrix, int midCol, int rows) {
    int maxIndex = 0;
    for (int i = 1; i < rows; i++) {
        if (matrix[i][midCol] > matrix[maxIndex][midCol]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
int find2DPeak(vector<vector<int>> &matrix, int leftCol, int rightCol, int rows) {
    if (leftCol > rightCol) return -1;
    int midCol = (leftCol + rightCol) / 2;
    int maxRow = findMaxIndex(matrix, midCol, rows);
    int left = (midCol > 0) ? matrix[maxRow][midCol - 1] : -1;
    int right = (midCol < matrix[0].size() - 1) ? matrix[maxRow][midCol + 1] : -1;
    if (matrix[maxRow][midCol] >= left && matrix[maxRow][midCol] >= right) {
        cout << "Peak found at: (" << maxRow << ", " << midCol << ") with value " << matrix[maxRow][midCol] << endl;
        return matrix[maxRow][midCol];
    } else if (left > matrix[maxRow][midCol]) {
        return find2DPeak(matrix, leftCol, midCol - 1, rows);
    } else {
        return find2DPeak(matrix, midCol + 1, rightCol, rows);
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    find2DPeak(matrix, 0, cols - 1, rows);
    return 0;
}
