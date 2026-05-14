#include <iostream>
#include <vector>
using namespace std;

const int COLS = 3;

void findUniqueElements(int arr[][COLS], int rows) {
    // Efficiency Issue: O((Rows*Cols)^2)
    // For every element, we scan the entire matrix again to check for duplicates.
    // If matrix is N*N, complexity is O(N^4).
    // Can be improved to O(N^2) using a Hash Map (unordered_map) to count frequencies first.
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            bool duplicate = false;
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
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int arr[3][COLS] = {
        {1, 2, 1},
        {3, 4, 2},
        {5, 6, 5}
    };
    findUniqueElements(arr, 3);
    return 0;
}
