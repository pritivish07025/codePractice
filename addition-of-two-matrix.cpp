#include <iostream>
using namespace std;

int main() {
    int row, col;

    // Input rows and columns
    cout << "Enter number of rows: ";
    cin >> row;

    cout << "Enter number of columns: ";
    cin >> col;

    int A[row][col], B[row][col], Sum[row][col];

    // Input first matrix
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> A[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> B[i][j];
        }
    }

    // Add matrices
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Display result
    cout << "Sum of matrices:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << Sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}