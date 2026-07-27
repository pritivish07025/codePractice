#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int product = (nums[i] - 1) * (nums[j] - 1);
            ans = max(ans, product);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum Product = " << maxProduct(nums);

    return 0;
}
