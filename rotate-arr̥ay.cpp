#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Store last element
    int last = arr[n - 1];

    // Shift elements to the right
    for(int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Place last element at first position
    arr[0] = last;

    cout << "Array after right rotation by 1 position: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}