#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);

        for (int i = l.size(); i <= h.size(); i++) {
            for (int j = 0; j <= 9 - i; j++) {
                string n = s.substr(j, i);
                int num = stoi(n);

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int low, high;

    cout << "Enter low: ";
    cin >> low;

    cout << "Enter high: ";
    cin >> high;

    vector<int> result = obj.sequentialDigits(low, high);

    cout << "Sequential Digits: ";
    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}