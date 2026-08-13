#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();

        int cnt = 0;

        unordered_map<int, int> freq;
        freq.reserve(n);

        for (int l = 0, r = 0; r < n; r++) {

            int x = nums[r];

            auto it = freq.find(x);
            

            int& f = (it == freq.end())
                        ? freq[x] = 1
                        : ++(it->second);

            while (f > k) {
                freq[nums[l++]]--;
            }

            cnt = max(cnt, r - l + 1);
        }

        return cnt;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;

    vector<int> nums = {1, 2, 1, 2, 3, 1, 1};
    int k = 2;

    int ans = obj.maxSubarrayLength(nums, k);

    cout << "Maximum Subarray Length: " << ans << endl;

    return 0;
}