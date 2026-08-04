#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> hasX;
        int xMin = 101, xMax = 0;

        for (int x : nums) {
            hasX[x] = 1;
            xMin = min(x, xMin);
            xMax = max(x, xMax);
        }

        vector<int> ans;

        for (int x = xMin + 1; x < xMax; x++) {
            if (!hasX[x]) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements (0 to 100): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = Solution::findMissingElements(nums);

    if (result.empty()) {
        cout << "No missing elements between the minimum and maximum values." << endl;
    } else {
        cout << "Missing elements: ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}