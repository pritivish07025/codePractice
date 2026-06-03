#include <iostream>
using namespace std;

void moveZerosToEnd(int arr[], int n) {
    int index = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[index], arr[i]);
            index++;
        }
    }
}

int main() {
    int arr[] = {1, 0, 2, 0, 3, 0, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZerosToEnd(arr, n);

    cout << "Array after moving zeros to end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}