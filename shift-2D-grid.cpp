#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> result(m, vector<int>(n));

    int total = m * n;
    k = k % total;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // Current position in 1D
            int currentIndex = i * n + j;

            // New position after shifting
            int newIndex = (currentIndex + k) % total;

            // Convert back to 2D
            int newRow = newIndex / n;
            int newCol = newIndex % n;

            result[newRow][newCol] = grid[i][j];
        }
    }

    return result;
}

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<vector<int>> ans = shiftGrid(grid, k);

    cout << "\nGrid after shifting:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}