#include <bits/stdc++.h>
using namespace std;

void findSubsets(vector<int>& arr, int index, vector<int>& current) {

    // Every state of current is a subset
    for (int x : current) {
        cout << x << " ";
    }
    cout << endl;

    // Try including each remaining element
    for (int i = index; i < arr.size(); i++) {

        // Include arr[i]
        current.push_back(arr[i]);

        // Recursively find subsets
        findSubsets(arr, i + 1, current);

        // Backtrack: remove the element
        current.pop_back();
    }
}

int main() {

    vector<int> arr = {1, 2, 3};
    vector<int> current;

    findSubsets(arr, 0, current);

    return 0;
}
