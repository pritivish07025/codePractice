// create 2d array and traverse over it.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(vector<int> row : arr){        // outer for-each: har row nikal rahe hain
        for(int x : row){              // inner for-each: row ke andar har element
            cout << x << " ";
        }
        cout << endl;
    }
}