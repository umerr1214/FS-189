#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 3;

void rotateMatrix(int matrix[][N], int n) {
    // Semantic Error: Confusion between row/column indices or using values as indices.
    
    // Let's assume we use the value of the matrix element as the index for swapping.
    // swap(matrix[i][j], matrix[matrix[i][j]][i]); // Semantic misuse of value as index.
    
    // Or let's use the assignment in loop condition again? 
    // Or bitwise operator for swap?
    // swap(matrix[i][j] ^ matrix[j][i], ...); 
    
    // Let's use pointer arithmetic semantic error.
    // Trying to swap rows by swapping pointers?
    // swap(matrix[i], matrix[n-1-i]); 
    // This is syntactically valid ONLY if matrix was int**, but matrix is int[][N].
    // Arrays are not assignable. `matrix[i]` is an array. `swap` on arrays might work if std::swap is specialized?
    // Actually std::swap on arrays works in C++11. So swapping rows might be correct for vertical flip!
    // That's a valid logical step.
    
    // Let's try:
    // matrix[i] = matrix[j]; // Compile error (array assignment).
    
    // Let's use `sizeof` semantic error again?
    // No, let's use `if (matrix[i][j] & matrix[j][i])`?
    
    // Let's go with: Modifying the loop index `i` inside the loop body using assignment.
    // for (int i = 0; i < n; i++) {
    //     i = n; // Terminates loop immediately.
    // }
    
    // Or comparing matrix row address with int?
    
    // Let's stick to using value as index.
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
             // Semantic Error: Using element value as index
             // This assumes elements are within [0, N-1]. If they are 1-9, OOB.
             int temp = matrix[matrix[i][j]][j]; // OOB if matrix[i][j] >= N
             matrix[matrix[i][j]][j] = matrix[j][i];
             matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Crash likely
    rotateMatrix(matrix, N);
    return 0;
}
