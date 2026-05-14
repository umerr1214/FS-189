#include <iostream>
using namespace std;

const int COLS = 4;

void printSpiral(int matrix[][COLS], int rows, int cols) {
    // Robustness Issue: No check for NULL if passed as pointer (int (*matrix)[COLS]).
    // No check for negative rows/cols.
    
    if (rows == 0 || cols == 0) return; // Basic check, but what if negative?
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    // If matrix is NULL, crash.
    // Assuming passed as array parameter which decays to pointer.
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " "; // Crash if NULL
        }
        top++;
        // ...
        break;
    }
    cout << endl;
}

int main() {
    // Crash
    // printSpiral(NULL, 4, 4);
    return 0;
}
