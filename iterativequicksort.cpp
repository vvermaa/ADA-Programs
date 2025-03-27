#include <iostream>
#include <stack>
using namespace std;
// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // Pointer for smaller elements
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Swap if element is smaller than pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return (i + 1);
}
// Iterative Quick Sort function
void quickSortIterative(int arr[], int low, int high) {
    stack<pair<int, int>> st;
    st.push({low, high}); // Push initial range
    while (!st.empty()) {
        // Pop the top range
        pair<int, int> range = st.top();
        st.pop();
        low = range.first;
        high = range.second;
        // Partition the array
        int pivotIndex = partition(arr, low, high);
        // Push larger subarray first, sort smaller one immediately
        if (pivotIndex - 1 - low > high - pivotIndex - 1) {
            if (low < pivotIndex - 1) st.push({low, pivotIndex - 1});
            low = pivotIndex + 1; // Continue sorting smaller array
        } else {
            if (pivotIndex + 1 < high) st.push({pivotIndex + 1, high});
            high = pivotIndex - 1; // Continue sorting smaller array
        }
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    quickSortIterative(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
