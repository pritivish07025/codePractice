#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> temp = arr;

    // Sort the copied array
    sort(temp.begin(), temp.end());

    unordered_map<int, int> rank;
    int currentRank = 1;

    // Assign ranks to unique elements
    for (int num : temp) {
        if (rank.find(num) == rank.end()) {
            rank[num] = currentRank++;
        }
    }

    // Replace elements with their ranks
    vector<int> result;
    for (int num : arr) {
        result.push_back(rank[num]);
    }

    return result;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};

    vector<int> ans = arrayRankTransform(arr);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}