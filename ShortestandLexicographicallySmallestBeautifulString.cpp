#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int r = 0; r < s.size(); r++) {

            // Count 1
            if (s[r] == '1') {
                ones++;
            }

            // When we have exactly k ones
            while (ones == k) {

                int len = r - l + 1;
                string curr = s.substr(l, len);

                // Shorter substring
                if (len < minLen) {
                    minLen = len;
                    ans = curr;
                }

                // Same length -> lexicographically smaller
                else if (len == minLen && curr < ans) {
                    ans = curr;
                }

                // Remove left character
                if (s[l] == '1') {
                    ones--;
                }

                l++;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    string result = obj.shortestBeautifulSubstring(s, k);

    cout << "Shortest Beautiful Substring: " << result << endl;

    return 0;
}
