#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minElement = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    cout << "Minimum element in the array is: " << minElement;

    return 0;
}