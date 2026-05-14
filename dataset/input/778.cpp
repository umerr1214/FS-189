#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

// Robustness: Passing raw array pointers without dimensions usually relies on constants.
// If we change constants but not array, buffer overflow.
// But let's assume standard pointer robustness issues.

void transposeMatrix(char matrix[][COLS]) {
    // Robustness Issue: No NULL check.
    // If matrix is NULL (passed as char(*)[COLS]), crash.
    
    cout << "Transpose:" << endl;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            cout << matrix[j][i] << " "; // Crash if NULL
        }
        cout << endl;
    }
}

int main() {
    // char (*matrix)[COLS] = NULL;
    // transposeMatrix(matrix);
    return 0;
}
