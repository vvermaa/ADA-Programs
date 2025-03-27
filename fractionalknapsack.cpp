#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to store weight and value of an item
struct Item {
    int weight, value;
};
// Function to compare items based on value/weight ratio
bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}
// Function to calculate max value for fractional knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);  // Sort items by value/weight
    double maxValue = 0.0;
    for (auto item : items) {
        if (W >= item.weight) {  // If full item can be taken
            maxValue += item.value;
            W -= item.weight;
        } else {  // Take fraction of item
            maxValue += (double)item.value * W / item.weight;
            break;
        }
    }
    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<Item> items(n);
    cout << "Enter weight and value of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Maximum Value: " << fractionalKnapsack(W, items) << endl;
    return 0;
}
