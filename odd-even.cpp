#include <iostream>
using namespace std;

int main() {
    int n, num;
    int evenCount = 0, oddCount = 0;

    cout << "Enter how many numbers: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter number " << i << ": ";
        cin >> num;

        if(num % 2 == 0) {
            cout << num << " is Even" << endl;
            evenCount++;
        } else {
            cout << num << " is Odd" << endl;
            oddCount++;
        }
    }

    cout << "\nTotal Even Numbers: " << evenCount << endl;
    cout << "Total Odd Numbers: " << oddCount << endl;

    return 0;
}
