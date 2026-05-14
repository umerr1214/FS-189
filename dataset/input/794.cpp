#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 3;

void rotateMatrix(int matrix[][N], int n) {
    // Logical Error: Incorrect loop range for transpose.
    // Instead of `j = i`, starting `j = 0` swaps elements twice, 
    // resulting in the original matrix (identity operation for transpose step).
    // Then reverse rows happens on non-transposed matrix.
    // Result is just horizontally flipped matrix, not rotated.
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { // Should be j = i
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reverse rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Expected:
    // 7 4 1
    // 8 5 2
    // 9 6 3
    
    // Actual (Horizontal Flip of original):
    // 3 2 1
    // 6 5 4
    // 9 8 7
    
    rotateMatrix(matrix, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
