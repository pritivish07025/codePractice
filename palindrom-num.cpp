#include <iostream>
using namespace std;

int main() {
    int num, originalNum, reverse = 0, remainder;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }

    // Check palindrome
    if (originalNum == reverse) {
        cout << originalNum << " is a Palindrome Number";
    } else {
        cout << originalNum << " is not a Palindrome Number";
    }

    return 0;
}