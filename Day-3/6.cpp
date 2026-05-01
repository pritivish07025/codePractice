#include <iostream>
using namespace std;
int main() {
    int n, num;
    int evenCount = 0, oddCount = 0;
    cout << "Enter how many numbers: ";
    cin >> n;
    cout << "Enter the numbers:\n";
    for(int i = 1; i <= n; i++) {
        cin >> num;

        if(num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    cout << "Even numbers count: " << evenCount << endl;
    cout << "Odd numbers count: " << oddCount << endl;

    return 0;
}
