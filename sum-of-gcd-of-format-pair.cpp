#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd;
        int maxEl = -1;

        // Construct the prefixGcd array
        for (int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);
            prefixGcd.push_back(__gcd(nums[i], maxEl));
        }

        // Sort the prefixGcd array
        sort(prefixGcd.begin(), prefixGcd.end());

        long long result = 0;
        int left = 0;
        int right = n - 1;

        // Form pairs from smallest and largest elements
        while (left < right) {
            result += __gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {6, 4, 9, 3};

    cout << "Sum of GCD of Formed Pairs: "
         << obj.gcdSum(nums) << endl;

    return 0;
}