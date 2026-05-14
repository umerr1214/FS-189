#include <iostream>

// Define maximum dimensions for the matrices
#define ROWS 3
#define COLS 3

// Function to check if two 2D integer matrices are identical.
// READABILITY/EFFICIENCY ISSUE:
// 1. Inefficient: It continues iterating through the entire matrix even after
//    a mismatch is found, instead of returning immediately.
// 2. Readability: Uses a flag variable unnecessarily instead of direct returns.
// 3. Readability: Inconsistent indentation and less descriptive variable names.
bool areMatricesEqual(int m1[ROWS][COLS], int m2[ROWS][COLS], int r, int c) {
    bool areIdentical = true; // Unnecessary flag variable

    // Loop through rows
    for (int rIdx = 0; rIdx < r; rIdx++) {
        // Loop through columns
      for (int cIdx = 0; cIdx < c; cIdx++) {
            // Check if elements are different
            if (m1[rIdx][cIdx] != m2[rIdx][cIdx]) {
                areIdentical = false; // Set flag to false
                // EFFICIENCY ISSUE: Continues iterating even after a mismatch is found
            }
        }
    }
    return areIdentical; // Return the flag's final value
}

// Helper function to print a matrix
void printMatrix(int mat[ROWS][COLS], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << mat[i][j] << (j == c - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrix1[ROWS][COLS] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int matrix2[ROWS][COLS] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int matrix3[ROWS][COLS] = {
        {10, 20, 30},
        {40, 55, 60}, // Different element
        {70, 80, 90}
    };

    int matrix4[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Matrix 1 (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrix1, ROWS, COLS);
    std::cout << "Matrix 2 (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrix2, ROWS, COLS);
    std::cout << "Matrix 3 (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrix3, ROWS, COLS);
    std::cout << "Matrix 4 (" << ROWS << "x" << COLS << "):\n";
    printMatrix(matrix4, ROWS, COLS);
    std::cout << std::endl;

    // Test Case 1: Identical matrices
    std::cout << "Comparing Matrix 1 and Matrix 2 (3x3): " << (areMatricesEqual(matrix1, matrix2, 3, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 2: Different matrices
    std::cout << "Comparing Matrix 1 and Matrix 3 (3x3): " << (areMatricesEqual(matrix1, matrix3, 3, 3) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 3: Comparing a sub-matrix (1x2)
    std::cout << "Comparing Matrix 1 and Matrix 2 (1x2 sub-matrix): " << (areMatricesEqual(matrix1, matrix2, 1, 2) ? "Equal" : "Not Equal") << std::endl;
    
    // Test Case 4: Comparing different matrices partially (2x2)
    std::cout << "Comparing Matrix 1 and Matrix 3 (2x2 sub-matrix): " << (areMatricesEqual(matrix1, matrix3, 2, 2) ? "Equal" : "Not Equal") << std::endl;

    // Test Case 5: Empty matrices (r=0, c=0)
    // The loops won't run, 'areIdentical' remains true. This is functionally correct for empty.
    std::cout << "Comparing Matrix 1 and Matrix 2 (0x0): " << (areMatricesEqual(matrix1, matrix2, 0, 0) ? "Equal" : "Not Equal") << std::endl;

    return 0;
}