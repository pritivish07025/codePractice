#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int result1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int result2 = nums[0] * nums[1] * nums[n - 1];

        return max(result1, result2);
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = obj.maximumProduct(nums);

    cout << "Maximum Product = " << ans << endl;

    return 0;
}