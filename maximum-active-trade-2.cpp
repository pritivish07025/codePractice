#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Count total number of 1's
        int ones = count(s.begin(), s.end(), '1');

        // Store start and end indices of every zero block
        vector<int> zs, ze;

        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0')
                    j++;

                zs.push_back(i);
                ze.push_back(j - 1);

                i = j;
            } else {
                i++;
            }
        }

        int nblocks = zs.size();

        // Valley values
        vector<int> V;
        for (int j = 0; j + 1 < nblocks; j++) {
            int leftLength = ze[j] - zs[j] + 1;
            int rightLength = ze[j + 1] - zs[j + 1] + 1;
            V.push_back(leftLength + rightLength);
        }

        // Sparse Table
        int nv = V.size();
        vector<vector<int>> sparse;
        sparse.push_back(V);

        for (int half = 1; half * 2 <= nv; half *= 2) {
            vector<int> next;

            for (int i = 0; i + half < (int)sparse.back().size(); i++) {
                next.push_back(max(sparse.back()[i], sparse.back()[i + half]));
            }

            sparse.push_back(next);
        }

        // Range Maximum Query
        auto rmq = [&](int lo, int hi) {
            int t = __lg(hi - lo + 1);
            return max(sparse[t][lo],
                       sparse[t][hi - (1 << t) + 1]);
        };

        // Clip function
        auto clip = [&](int j, int l, int r) {
            return V[j]
                 - max(0, l - zs[j])
                 - max(0, ze[j + 1] - r);
        };

        // Gain calculation
        auto gain = [&](int l, int r) {
            if (nblocks < 2)
                return 0;

            int ja = lower_bound(ze.begin(), ze.end(), l) - ze.begin();

            int jb = upper_bound(zs.begin(), zs.end(), r) - zs.begin() - 2;

            if (ja > jb)
                return 0;

            int ans = max(clip(ja, l, r), clip(jb, l, r));

            if (jb - ja >= 2)
                ans = max(ans, rmq(ja + 1, jb - 1));

            return ans;
        };

        vector<int> ans;

        for (auto &q : queries) {
            ans.push_back(ones + gain(q[0], q[1]));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "1001001";

    vector<vector<int>> queries = {
        {0, 6},
        {2, 5},
        {1, 4}
    };

    vector<int> ans = obj.maxActiveSectionsAfterTrade(s, queries);

    cout << "Answer: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}