#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        vector<int> result = nums;

        int start = 0;

        while (start < n) {

            int end = start;

            // Find elements belonging to the same group
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Get original indices of this group
            vector<int> indices;
            vector<int> values;

            for (int i = start; i <= end; i++) {
                values.push_back(arr[i].first);
                indices.push_back(arr[i].second);
            }

            // Sort indices
            sort(indices.begin(), indices.end());

            // Assign smallest values to smallest indices
            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return result;
    }
};

int main() {

    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;

    Solution obj;

    vector<int> ans =
        obj.lexicographicallySmallestArray(nums, limit);

    cout << "Lexicographically Smallest Array: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
