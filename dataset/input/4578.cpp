#include <iostream>

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

bool areMatricesEqual(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // Semantic Error: The function ignores the 'rows' and 'cols' parameters
    // and always iterates up to the global MAX_ROWS and MAX_COLS.
    // This means it will compare the full declared matrices, even if the caller
    // intended to compare a smaller sub-section. This can lead to incorrect
    // results or even out-of-bounds access if the actual matrices passed were smaller.
    
    // For this specific case, we assume matrices are at least MAX_ROWS x MAX_COLS in size.
    // The error is comparing more elements than specified by 'rows' and 'cols'.
    for (int i = 0; i < MAX_ROWS; ++i) { // Should use 'rows' here
        for (int j = 0; j < MAX_COLS; ++j) { // Should use 'cols' here
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

    int matrix4[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0} // Different at [2][2] from matrix1
    };
    
    // Test Case 1: Identical 3x3 matrices
    // Correctly reports equal, as MAX_ROWS/COLS match requested rows/cols
    if (areMatricesEqual(matrix1, matrix2, 3, 3)) {
        std::cout << "Test 1: Matrices are equal." << std::endl;
    } else {
        std::cout << "Test 1: Matrices are not equal." << std::endl;
    }

    // Test Case 2: Different 3x3 matrices
    // Correctly reports not equal, as MAX_ROWS/COLS match requested rows/cols
    if (areMatricesEqual(matrix1, matrix3, 3, 3)) {
        std::cout << "Test 2: Matrices are equal." << std::endl;
    } else {
        std::cout << "Test 2: Matrices are not equal." << std::endl;
    }

    // Test Case 3: Identical 2x2 submatrices (will incorrectly report not equal)
    // The intention is to compare only the top-left 2x2, which are identical.
    // However, the function will compare the full 3x3 and find matrix1[2][2] != matrix4[2][2].
    if (areMatricesEqual(matrix1, matrix4, 2, 2)) {
        std::cout << "Test 3: Matrices (2x2) are equal." << std::endl;
    } else {
        std::cout << "Test 3: Matrices (2x2) are not equal." << std::endl;
    }

    return 0;
}