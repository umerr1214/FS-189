#include <iostream>
using namespace std;

const int COLS = 4;

void printSpiral(int matrix[][COLS], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        
        // Print right column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        
        // Logical Error: Missing check `if (top <= bottom)` before printing bottom row.
        // If top has crossed bottom (e.g. single row matrix), this will print the row again backwards.
        
        for (int i = right; i >= left; i--) {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;
        
        // Logical Error: Missing check `if (left <= right)` before printing left column.
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << " ";
        }
        left++;
    }
    cout << endl;
}

int main() {
    int matrix[1][COLS] = {
        {1, 2, 3, 4}
    };
    
    // Expected: 1 2 3 4
    // Actual: 1 2 3 4 3 2 1 (reprints bottom row which is same as top row)
    
    printSpiral(matrix, 1, 4);
    return 0;
}
