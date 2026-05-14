#include <iostream>
#include <vector> // Not strictly needed for fixed-size arrays, but useful for general matrix ops

// Define maximum dimensions for the matrices.
// The function signature uses these as compile-time bounds.
#define ROWS 3
#define COLS 3

// Function to check if two 2D integer matrices are identical.
// ROBUSTNESS ISSUE: This function does NOT check if the 'rows' and 'cols'
// parameters exceed the compile-time defined ROWS and COLS.
// If 'rows' > ROWS or 'cols' > COLS, it will lead to out-of-bounds memory access,
// causing undefined behavior or a crash.
bool areMatricesEqual(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int rows, int cols) {
    // No checks for rows > ROWS or cols > COLS
    // No checks for negative rows or cols (though loops handle it by not running)

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat1[i][j] != mat2[i][j]) {
                return false; // Mismatch found
            }
        }
    }
    return true; // All elements match
}

// Helper function to print a matrix (for demonstration purposes)
void printMatrix(int mat[ROWS][COLS], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << mat[i][j] << (j == c - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example matrices within bounds
    int matrixA[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixC[ROWS][COLS] = {
        {1, 2, 3},
        {4, 0, 6}, // Different element
        {7, 8, 9}
    };

    std::cout << "Matrix A (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrixA, ROWS, COLS);
    std::cout << "Matrix B (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrixB, ROWS, COLS);
    std::cout << "Matrix C (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrixC, ROWS, COLS);
    std::cout << std::endl;

    // Test Case 1: Identical matrices
    std::cout << "Comparing A and B (3x3): " << (areMatricesEqual(matrixA, matrixB, 3, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 2: Different matrices
    std::cout << "Comparing A and C (3x3): " << (areMatricesEqual(matrixA, matrixC, 3, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 3: Comparing a sub-matrix (2x2)
    std::cout << "Comparing A and B (2x2 sub-matrix): " << (areMatricesEqual(matrixA, matrixB, 2, 2) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 4: Robustness Issue Demonstration (out-of-bounds access)
    // This call will likely cause a crash or undefined behavior because
    // 'rows' (4) exceeds the declared ROWS (3).
    std::cout << "\nAttempting to compare A and B with dimensions 4x3 (EXPECTING CRASH/UNDEFINED BEHAVIOR):\n";
    std::cout << "Comparing A and B (4x3): " << (areMatricesEqual(matrixA, matrixB, 4, 3) ? "Equal" : "Not Equal") << std::endl;
    
    // Another out-of-bounds example
    std::cout << "\nAttempting to compare A and C with dimensions 3x4 (EXPECTING CRASH/UNDEFINED BEHAVIOR):\n";
    std::cout << "Comparing A and C (3x4): " << (areMatricesEqual(matrixA, matrixC, 3, 4) ? "Equal" : "Not Equal") << std::endl;

    return 0;
}