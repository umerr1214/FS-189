#include <iostream>
#include <vector>

// Function `isSymmetric` with a logical error
bool isSymmetric(int** matrix, int dimension) {
    if (dimension <= 1) {
        return true;
    }

    // LOGICAL ERROR: The outer loop iterates up to `dimension - 1`,
    // causing the last row (index `dimension - 1`) to be entirely skipped from comparison.
    for (int i = 0; i < dimension - 1; ++i) { // Should be `i < dimension`
        for (int j = 0; j < dimension; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// Helper function to create a dynamic 2D array for testing
int** createMatrix(const std::vector<std::vector<int>>& vec_matrix, int dimension) {
    int** matrix = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matrix[i] = new int[dimension];
        for (int j = 0; j < dimension; ++j) {
            matrix[i][j] = vec_matrix[i][j];
        }
    }
    return matrix;
}

// Helper function to delete a dynamic 2D array
void deleteMatrix(int** matrix, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    // Test Case 1: Symmetric matrix (should pass)
    std::vector<std::vector<int>> mat1_vec = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    int dim1 = 3;
    int** mat1 = createMatrix(mat1_vec, dim1);
    std::cout << "Matrix 1 (Symmetric) is symmetric: " << (isSymmetric(mat1, dim1) ? "true" : "false") << std::endl;
    deleteMatrix(mat1, dim1);

    // Test Case 2: Non-symmetric matrix, asymmetry NOT in the last row (should pass, but logic error doesn't affect this)
    std::vector<std::vector<int>> mat2_vec = {
        {1, 2, 3},
        {4, 5, 6}, // matrix[1][0] != matrix[0][1]
        {7, 8, 9}
    };
    int dim2 = 3;
    int** mat2 = createMatrix(mat2_vec, dim2);
    std::cout << "Matrix 2 (Non-symmetric, early) is symmetric: " << (isSymmetric(mat2, dim2) ? "true" : "false") << std::endl;
    deleteMatrix(mat2, dim2);

    // Test Case 3: Non-symmetric matrix, asymmetry IS in the last row (should fail, but code returns true)
    std::vector<std::vector<int>> mat3_vec = {
        {1, 2, 4},
        {2, 5, 0},
        {3, 0, 9} // matrix[2][0] = 3, matrix[0][2] = 4. This is the asymmetry.
                  // The loop `i < dimension - 1` will miss `i=2`, so it won't check matrix[2][0] vs matrix[0][2].
    };
    int dim3 = 3;
    int** mat3 = createMatrix(mat3_vec, dim3);
    std::cout << "Matrix 3 (Non-symmetric, last row) is symmetric: " << (isSymmetric(mat3, dim3) ? "true" : "false") << std::endl;
    deleteMatrix(mat3, dim3);

    return 0;
}