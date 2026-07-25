#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int product = 1;

    // Handle the case when the number is 0
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    n = abs(n); // Handle negative numbers

    while (n > 0) {
        int digit = n % 10;
        product *= digit;
        n /= 10;
    }

    cout << product << endl;

    return 0;
}