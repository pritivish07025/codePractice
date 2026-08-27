#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        // Count frequency of each character in s
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Store the prefix that matches target
        string prefix;

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Character is not available
            if (cnt[x] == 0) {
                break;
            }

            cnt[x]--;
            prefix += target[i];
        }

        // If we could not match the entire target,
        // try placing a character greater than target[i]
        if ((int)prefix.size() < n) {
            int i = prefix.size();
            int x = target[i] - 'a';

            // Find the smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] == 0) {
                    continue;
                }

                string ans = prefix;
                ans += char('a' + c);

                cnt[c]--;

                // Append remaining characters in sorted order
                for (int ch = 0; ch < 26; ch++) {
                    ans.append(cnt[ch], char('a' + ch));
                }

                return ans;
            }
        }

        // Backtrack through the matched prefix
        for (int i = (int)prefix.size() - 1; i >= 0; i--) {

            // Restore the character at position i
            cnt[prefix[i] - 'a']++;

            prefix.pop_back();

            int x = target[i] - 'a';

            // Find the smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] == 0) {
                    continue;
                }

                string ans = prefix;
                ans += char('a' + c);

                cnt[c]--;

                // Fill remaining characters in sorted order
                for (int ch = 0; ch < 26; ch++) {
                    ans.append(cnt[ch], char('a' + ch));
                }

                return ans;
            }
        }

        // No permutation greater than target exists
        return "";
    }
};
