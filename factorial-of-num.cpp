#include <iostream>
using namespace std;

int main() {
    int num;
    long long factorial = 1;

    cout << "Enter a number: ";
    cin >> num;

    // Check for negative number
    if (num < 0) {
        cout << "Factorial of a negative number does not exist.";
    }
    else {
        // Calculate factorial
        for (int i = 1; i <= num; i++) {
            factorial = factorial * i;
        }

        cout << "Factorial of " << num << " is " << factorial;
    }

    return 0;
}