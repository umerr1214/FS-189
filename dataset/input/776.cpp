#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void transposeMatrix(char matrix[][COLS]) {
    cout << "Transpose:" << endl;
    // Logical Error: Using ROWS limit for outer loop (i) and COLS for inner (j)
    // but accessing matrix[j][i].
    // If ROWS != COLS, indices will be out of bounds or skip elements.
    // Transpose of 3x4 is 4x3. Outer loop should be COLS, inner ROWS.
    
    for (int i = 0; i < ROWS; i++) { // Should be COLS
        for (int j = 0; j < COLS; j++) { // Should be ROWS
            // Accessing matrix[j][i].
            // i goes 0..2. j goes 0..3.
            // matrix[0][0] OK
            // matrix[3][0] -> OOB (Row index 3 is invalid for 3 rows 0..2)
            cout << matrix[j][i] << " "; 
        }
        cout << endl;
    }
}

int main() {
    char matrix[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'}
    };
    
    // Expected: 4 rows output
    // Actual: 3 rows output, with OOB access printing garbage or crashing
    transposeMatrix(matrix);
    return 0;
}
