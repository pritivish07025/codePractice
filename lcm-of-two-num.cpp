#include <iostream>
using namespace std;

int main() {
    int a, b, lcm, max;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    max = (a > b) ? a : b;

    while (true) {
        if (max % a == 0 && max % b == 0) {
            lcm = max;
            break;
        }
        max++;
    }

    cout << "LCM = " << lcm;

    return 0;
}