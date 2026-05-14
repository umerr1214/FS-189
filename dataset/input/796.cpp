#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 3;

void rotateMatrix(int matrix[][N], int n) {
    // Robustness Issue: No check if n exceeds N (fixed dim).
    // If n > N, we access OOB.
    
    for (int i = 0; i < n; i++) { // if n > N, crash
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

int main() {
    int matrix[N][N] = {{1}};
    // Crash or Garbage
    // rotateMatrix(matrix, 10);
    return 0;
}
