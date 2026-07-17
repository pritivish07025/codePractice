#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>   // for gcd()

using namespace std;

vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    vector<int> gcdPairs;
    int n = nums.size();

    // Step 1: Calculate GCD of every pair
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            gcdPairs.push_back(__gcd(nums[i], nums[j]));
        }
    }

    // Step 2: Sort the GCD values
    sort(gcdPairs.begin(), gcdPairs.end());

    // Step 3: Answer the queries
    vector<int> ans;
    for (long long idx : queries) {
        ans.push_back(gcdPairs[idx]);
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 3, 4};
    vector<long long> queries = {0, 2, 2};

    vector<int> ans = gcdValues(nums, queries);

    cout << "Answer: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}