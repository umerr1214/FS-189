#include <iostream>
#include <string> // For error messages

// Define maximum dimensions for the matrices.
// These are the compile-time bounds for the arrays.
#define ROWS 3
#define COLS 3

// Function to check if two 2D integer matrices are identical.
// This is the CORRECT and ROBUST version.
// It handles edge cases, performs bounds checking, and is efficient.
bool areMatricesEqual(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int rows, int cols) {
    // Robustness: Check for invalid dimensions (negative values).
    // A negative dimension doesn't make sense for a matrix size.
    if (rows < 0 || cols < 0) {
        std::cerr << "Error: Matrix dimensions cannot be negative (rows=" << rows << ", cols=" << cols << ")." << std::endl;
        return false; // Or throw an exception
    }

    // Robustness: Check if the requested comparison dimensions exceed the
    // declared compile-time maximum dimensions (ROWS, COLS).
    // Accessing beyond these bounds would lead to undefined behavior.
    if (rows > ROWS || cols > COLS) {
        std::cerr << "Error: Comparison dimensions (" << rows << "x" << cols << ") exceed declared matrix capacity (" << ROWS << "x" << COLS << ")." << std::endl;
        return false; // Cannot safely compare beyond allocated memory
    }

    // Edge Case: If either dimension is zero, it means we are comparing two "empty"
    // sections of the matrices. Logically, two empty matrices are considered equal.
    if (rows == 0 || cols == 0) {
        return true;
    }

    // Efficient comparison: Iterate through elements and return false immediately on mismatch.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat1[i][j] != mat2[i][j]) {
                return false; // Mismatch found, no need to check further
            }
        }
    }

    return true; // All elements within the specified dimensions match
}

// Helper function to print a matrix
void printMatrix(int mat[ROWS][COLS], int r, int c) {
    if (r <= 0 || c <= 0) {
        std::cout << "[Empty Matrix]" << std::endl;
        return;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << mat[i][j] << (j == c - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
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

    // Matrices for edge cases (physically declared, but logically empty parts)
    int emptyMat1[ROWS][COLS] = {{0}}; // Technically not empty, but if we pass 0,0
    int emptyMat2[ROWS][COLS] = {{0}};

    std::cout << "Matrix A (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrixA, ROWS, COLS);
    std::cout << "Matrix B (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrixB, ROWS, COLS);
    std::cout << "Matrix C (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrixC, ROWS, COLS);
    std::cout << std::endl;

    // Test Case 1: Identical matrices (full size)
    std::cout << "Comparing A and B (3x3): " << (areMatricesEqual(matrixA, matrixB, 3, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 2: Different matrices (full size)
    std::cout << "Comparing A and C (3x3): " << (areMatricesEqual(matrixA, matrixC, 3, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 3: Identical sub-matrices (2x2)
    std::cout << "Comparing A and B (2x2 sub-matrix): " << (areMatricesEqual(matrixA, matrixB, 2, 2) ? "Equal" : "Not Equal") << std::endl;
    
    // Test Case 4: Comparing with zero dimensions (empty matrices)
    std::cout << "Comparing A and B (0x0): " << (areMatricesEqual(matrixA, matrixB, 0, 0) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 5: Invalid dimensions (negative rows) - Robustness check
    std::cout << "Comparing A and B (-1x3): " << (areMatricesEqual(matrixA, matrixB, -1, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 6: Dimensions exceeding declared capacity - Robustness check
    std::cout << "Comparing A and B (4x3 - exceeding ROWS): " << (areMatricesEqual(matrixA, matrixB, 4, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 7: Dimensions exceeding declared capacity - Robustness check
    std::cout << "Comparing A and C (3x4 - exceeding COLS): " << (areMatricesEqual(matrixA, matrixC, 3, 4) ? "Equal" : "Not Equal") << std::endl;

    return 0;
}