#include <iostream>
#include <string>
using namespace std;

int main() {
    string binary;
    int decimal = 0;

    cout << "Enter a binary number: ";
    cin >> binary;

    for (int i = 0; i < binary.length(); i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }

    cout << "Decimal equivalent = " << decimal << endl;

    return 0;
}