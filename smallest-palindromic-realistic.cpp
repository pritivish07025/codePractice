#include <iostream>
#include <vector>
#include <string>
using namespace std;

string smallestPalindrome(string s) {
    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char c : s)
        freq[c - 'a']++;

    int n = s.size();
    string ans(n, ' ');

    int left = 0, right = n - 1;

    // Build the smallest palindrome
    for (int i = 0; i < 26; i++) {
        while (freq[i] >= 2) {
            ans[left++] = char('a' + i);
            ans[right--] = char('a' + i);
            freq[i] -= 2;
        }

        // Place the odd frequency character in the middle
        if (freq[i] == 1) {
            ans[n / 2] = char('a' + i);
        }
    }

    return ans;
}

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Smallest Palindrome: " << smallestPalindrome(s) << endl;

    return 0;
}