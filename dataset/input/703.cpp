#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int COLS = 3;

void findUniqueElements(int arr[][COLS], int rows) {
    vector<int> unique;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            bool duplicate = false;
            // Check if arr[i][j] appears elsewhere in the array
            for (int k = 0; k < rows; k++) {
                for (int l = 0; l < COLS; l++) {
                    if ((i != k || j != l) && arr[i][j] == arr[k][l]) {
                        duplicate = true;
                        break;
                    }
                }
                if (duplicate) break;
            }
            if (!duplicate) {
                unique.push_back(arr[i][j]);
            }
        }
    }
    
    for (int x : unique) {
        cout << x << " ";
    }
    cout << endl
} // Syntax Error: Missing semicolon

int main() {
    int arr[3][COLS] = {
        {1, 2, 1},
        {3, 4, 2},
        {5, 6, 5}
    };
    findUniqueElements(arr, 3);
    return 0;
}
