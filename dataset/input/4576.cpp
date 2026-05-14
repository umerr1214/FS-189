#include <iostream>

const int MAX_ROWS = 3;
const int MAX_COLS = 3 // Syntax Error: Missing semicolon here

bool areMatricesEqual(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int rows, int cols) {
    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        // In a real scenario, this might throw an exception or handle error.
        // For this problem, we assume valid dimensions <= MAX_ROWS/COLS.
        return false; 
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix3[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 0, 6}, // Different at [1][1]
        {7, 8, 9}
    };
    
    // Test Case 1: Identical 3x3 matrices
    if (areMatricesEqual(matrix1, matrix2, 3, 3)) {
        std::cout << "Test 1: Matrices are equal." << std::endl;
    } else {
        std::cout << "Test 1: Matrices are not equal." << std::endl;
    }

    // Test Case 2: Different 3x3 matrices
    if (areMatricesEqual(matrix1, matrix3, 3, 3)) {
        std::cout << "Test 2: Matrices are equal." << std::endl;
    } else {
        std::cout << "Test 2: Matrices are not equal." << std::endl;
    }

    // Test Case 3: Identical 2x2 submatrices
    if (areMatricesEqual(matrix1, matrix2, 2, 2)) {
        std::cout << "Test 3: Matrices (2x2) are equal." << std::endl;
    } else {
        std::cout << "Test 3: Matrices (2x2) are not equal." << std::endl;
    }

    return 0;
}