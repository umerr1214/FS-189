#include <iostream>
#include <vector>
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
                    // Logical Error: Incorrect comparison logic.
                    // It assumes that if we find *any* match, it's a duplicate.
                    // But we must ignore the current element itself (when i==k && j==l).
                    // The check (i != k || j != l) is attempting this, but let's break it.
                    
                    // Error: We check if equal, but forgot to exclude self-check.
                    if (arr[i][j] == arr[k][l]) {
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
    
    // With this error, every element will find itself as a match and be marked duplicate.
    // So 'unique' vector will be empty.
    
    cout << "Unique elements: ";
    for (int x : unique) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int arr[3][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // Expected: 1 2 3 4 5 6 7 8 9
    // Actual: (empty)
    findUniqueElements(arr, 3);
    return 0;
}
