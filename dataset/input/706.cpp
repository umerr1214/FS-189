#include <iostream>
#include <vector>
using namespace std;

// Robustness: Missing COLS dimension in parameter or reliance on global constant
// which might mismatch passed array if not careful.
// But standard issue: NULL pointer check (though 2D array decay is tricky).
// If passed as int** it handles NULL.
// Let's change signature to int** to demonstrate robustness issue easily.

void findUniqueElements(int** arr, int rows, int cols) {
    // Robustness Issue: No NULL check for arr or arr[i]
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Crash if arr is NULL or arr[i] is NULL
            int current = arr[i][j];
            bool duplicate = false;
            
            for (int k = 0; k < rows; k++) {
                for (int l = 0; l < cols; l++) {
                    if ((i != k || j != l) && arr[k][l] == current) {
                        duplicate = true;
                        break;
                    }
                }
                if (duplicate) break;
            }
            if (!duplicate) cout << current << " ";
        }
    }
    cout << endl;
}

int main() {
    int** arr = NULL;
    // Crash
    // findUniqueElements(arr, 3, 3);
    return 0;
}
