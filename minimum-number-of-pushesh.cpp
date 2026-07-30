#include <iostream>
#include <string>
using namespace std;

int minimumPushes(string A) {
    int q = A.size() >> 3;   // Equivalent to A.size() / 8
    int r = A.size() & 7;    // Equivalent to A.size() % 8

    return ((q << 2) + r) * (q + 1);
}

int main() {
    string A;

    cout << "Enter the string: ";
    cin >> A;

    int result = minimumPushes(A);

    cout << "Minimum Pushes = " << result << endl;

    return 0;
}