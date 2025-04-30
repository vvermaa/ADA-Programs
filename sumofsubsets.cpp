#include <iostream>
using namespace std;

int n, targetSum;
int arr[100], subset[100];

void sumOfSubsets(int index, int currSum, int subsetIndex) {
    if (currSum == targetSum) {
        // Print the current subset
        cout << "{ ";
        for (int i = 0; i < subsetIndex; i++) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    if (index == n || currSum > targetSum) return;

    // Include arr[index]
    subset[subsetIndex] = arr[index];
    sumOfSubsets(index + 1, currSum + arr[index], subsetIndex + 1);

    // Exclude arr[index]
    sumOfSubsets(index + 1, currSum, subsetIndex);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter the target sum: ";
    cin >> targetSum;

    cout << "\nSubsets with sum " << targetSum << " are:\n";
    sumOfSubsets(0, 0, 0);

    return 0;
}
