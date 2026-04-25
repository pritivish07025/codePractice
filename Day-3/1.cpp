#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        cout << "Uppercase letter";
    }
    else if (ch >= 'a' && ch <= 'z') {
        cout << "Lowercase letter";
    }
    else {
        cout << "Not an alphabet character";
    }

    return 0;
}
