#include <iostream>
using namespace std;

int main() {
    int n,  sum = 0;

    cout << "Enter how many numbers: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {     
        sum += n;
    }
    cout << "Sum = " << sum;

    return 0;
}
