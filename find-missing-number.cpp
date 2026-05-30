#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10}; // 7 is missing
    int n = 9;

    int totalSum = 10 * 11 / 2; // Sum of numbers from 1 to 10
    int arraySum = 0;

    for (int i = 0; i < n; i++) {
        arraySum += arr[i];
    }

    int missingNumber = totalSum - arraySum;

    cout << "Missing Number: " << missingNumber << endl;

    return 0;
}