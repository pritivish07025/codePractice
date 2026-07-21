#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSections(string s) {
        int n = s.size();

        // Count original active sections
        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        // Augmented string
        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char, int>> blocks;

        // Run Length Encoding
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i])
                j++;

            blocks.push_back({t[i], j - i});
            i = j;
        }

        int ans = totalOnes;

        // Try removing every valid 1-block
        for (int i = 1; i + 1 < (int)blocks.size(); i++) {

            // Must be a 1-block surrounded by 0-blocks
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int removed = blocks[i].second;

                // merged zero block length
                int mergedZero = blocks[i - 1].second +
                                 removed +
                                 blocks[i + 1].second;

                int current = totalOnes - removed + mergedZero;
                ans = max(ans, current);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.maxActiveSections(s);

    return 0;
}