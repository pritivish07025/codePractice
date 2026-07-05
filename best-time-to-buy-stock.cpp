#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {

    int maxProfit = 0;

    for(int i = 0; i < prices.size(); i++) {

        for(int j = i + 1; j < prices.size(); j++) {

            if(prices[j] > prices[i]) {

                maxProfit = max(maxProfit, prices[j] - prices[i]);

            }
        }
    }

    return maxProfit;
}

int main() {

    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}