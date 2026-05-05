#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int i = s.length() - 1;
        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && s[i] == ' ')
                i--;
            if (i < 0) break;
            int j = i;
            // Find start of word
            while (i >= 0 && s[i] != ' ')
                i--;
            // Add space if result is not empty
            if (!result.empty())
                result += ' ';

            // Add word to result
            result += s.substr(i + 1, j - i);
        }

        return result;
    }
};

int main() {
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input);  // To take full line input

    Solution obj;
    string output = obj.reverseWords(input);

    cout << "Reversed words: " << output << endl;

    return 0;
}
