#include <iostream>
#include <vector>
using namespace std;

bool stoneGame(vector<int>& piles) {
    return true;
}

int main() {
    int n;

    cout << "Enter the number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter the stones in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    if (stoneGame(piles))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}