#include <iostream>
using namespace std;

int main() {
    int n, key;

    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter array elements: ";  
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Element to search
    cout << "Enter element to search: ";
    cin >> key;
   
    // Linear Search
    bool found = false;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    // If element not found
    if(!found) {
        cout << "Element not found" << endl;
    }

    return 0;
}