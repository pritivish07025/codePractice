#include <iostream>
using namespace std;

int smallestNumber(int n, int t) {
    while (true) {
        int product = 1;
        int x = n;

        while (x > 0) {
            product *= (x % 10);
            x /= 10;
        }

        if (product % t == 0)
            return n;

        n++;
    }
}

int main() {
    int n, t;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the value of t: ";
    cin >> t;

    int result = smallestNumber(n, t);

    cout << "Smallest Number = " << result << endl;

    return 0;
}