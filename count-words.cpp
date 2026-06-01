#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);

    stringstream ss(str);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    cout << "Number of words = " << count << endl;

    return 0;
}