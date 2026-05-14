#include <iostream>
using namespace std;

const int COLS = 4;

void printSpiral(int matrix[][COLS], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        // Semantic Error: Confusion between row/col indices when accessing matrix.
        // matrix[row][col] is standard.
        // Let's use matrix[col][row] or similar.
        
        // Or using assignment in loop condition?
        
        // Let's use:
        // cout << matrix[i][top] ... inside the first loop?
        // First loop `for i = left to right`. Accessing `matrix[top][i]` is correct.
        // If we use `matrix[i][top]`, we access [0..3][0]. That's the left column, not top row.
        
        for (int i = left; i <= right; i++) {
            cout << matrix[i][top] << " "; // Semantic Error: Swapped indices
            // Accessing matrix[i][top] instead of matrix[top][i].
            // If i goes up to COLS-1, and rows < COLS, this might be OOB if i >= ROWS.
            // e.g. matrix 4x4. i goes 0..3. top=0.
            // matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0].
            // Prints first column instead of first row.
        }
        top++;
        
        // ... rest of logic
        break; // Stop to limit output
    }
    cout << endl;
}

int main() {
    int matrix[4][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    // Expected: 1 2 3 4 ...
    // Actual: 1 5 9 13 ... (First column)
    printSpiral(matrix, 4, 4);
    return 0;
}
