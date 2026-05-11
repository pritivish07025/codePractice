#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, originalNum, remainder, result = 0, n = 0;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;

    // Count number of digits
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        ++n;
    }

    temp = num;

    // Calculate Armstrong number
    while (temp != 0) {
        remainder = temp % 10;
        result += pow(remainder, n);
        temp /= 10;
    }

    // Check Armstrong
    if (result == originalNum)
        cout << originalNum << " is an Armstrong Number";
    else
        cout << originalNum << " is not an Armstrong Number";

    return 0;
}