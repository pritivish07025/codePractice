#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    for(int i = 0; i < nums.size(); i++) {

        for(int j = i + 1; j < nums.size(); j++) {

            if(nums[i] + nums[j] == target) {
                return {i, j};
            }

        }

    }

    return {};
}

int main() {

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    cout << "Indices: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}