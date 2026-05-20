#include <iostream>
#include <climits>
using namespace std;

int main() {
    
    int arr[] = {12, 45, 7, 89, 34, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        cout << "No second largest element found.";
    } 
    else {
        cout << "Second Largest Element: " << secondLargest;
    }

    return 0;
}