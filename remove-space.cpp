#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";

    for (char ch : str) {
        if (ch != ' ') {
            result += ch;
        }
    }

    cout << "String after removing spaces: " << result;

    return 0;
}