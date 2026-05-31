#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // N

    int arr[n - 1];
    int sum = 0;

    for(int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int totalSum = n * (n + 1) / 2;
    int missingNumber = totalSum - sum;

    cout << "Missing Number = " << missingNumber;

    return 0;
}