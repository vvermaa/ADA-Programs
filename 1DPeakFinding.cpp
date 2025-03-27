#include <iostream>
using namespace std;

int findPeak(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && 
        (mid == n - 1 || arr[mid] >= arr[mid + 1]))
        return arr[mid];

    if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeak(arr, low, mid - 1, n);
    
    return findPeak(arr, mid + 1, high, n);
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Peak element: " << findPeak(arr, 0, n - 1, n) << endl;
    return 0;
}
