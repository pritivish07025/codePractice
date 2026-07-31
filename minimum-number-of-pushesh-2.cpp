#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> charCount(26, 0);

        // Count frequency of each character
        for (char ch : word) {
            charCount[ch - 'a']++;
        }

        // Sort frequencies in descending order
        sort(charCount.begin(), charCount.end(), greater<int>());

        int minPushCount = 0;

        // Calculate minimum pushes
        for (int i = 0; i < 26; i++) {
            minPushCount += charCount[i] * (i / 8 + 1);
        }

        return minPushCount;
    }
};

int main() {
    Solution obj;
    string word;

    cout << "Enter the word: ";
    cin >> word;

    cout << "Minimum Pushes = " << obj.minimumPushes(word) << endl;

    return 0;
}