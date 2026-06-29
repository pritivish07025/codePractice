#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Create LPS array
    void createLPS(string pattern, vector<int>& lps)
    {
        int len = 0;
        int i = 1;

        lps[0] = 0;

        while(i < pattern.length())
        {
            if(pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }


    // KMP Search
    bool KMP(string word, string pattern)
    {
        vector<int> lps(pattern.length());

        createLPS(pattern, lps);

        int i = 0; // word index
        int j = 0; // pattern index


        while(i < word.length())
        {
            if(word[i] == pattern[j])
            {
                i++;
                j++;
            }


            // Pattern found
            if(j == pattern.length())
            {
                return true;
            }


            // Mismatch
            else if(i < word.length() && word[i] != pattern[j])
            {
                if(j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return false;
    }



    int numOfStrings(vector<string>& patterns, string word)
    {
        int count = 0;


        for(string pattern : patterns)
        {
            if(KMP(word, pattern))
            {
                count++;
            }
        }


        return count;
    }
};



int main()
{
    Solution obj;


    vector<string> patterns = {"a","abc","bc","d"};

    string word = "abc";


    int ans = obj.numOfStrings(patterns, word);


    cout << "Answer: " << ans << endl;


    return 0;
}