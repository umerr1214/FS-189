#include <iostream>
#include <vector>

// Function `isSymmetric` with a syntax error
bool isSymmetric(int** matrix, int dimension) {
    if (dimension <= 1) {
        retun true; // SYNTAX ERROR: Typo 'retun' instead of 'return'
    }

    for (int i = 0; i < dimension; ++i) {
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
    // Test Case 1: Symmetric matrix
    std::vector<std::vector<int>> mat1_vec = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    int dim1 = 3;
    int** mat1 = createMatrix(mat1_vec, dim1);
    std::cout << "Matrix 1 is symmetric: " << (isSymmetric(mat1, dim1) ? "true" : "false") << std::endl;
    deleteMatrix(mat1, dim1);

    // Test Case 2: Non-symmetric matrix
    std::vector<std::vector<int>> mat2_vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int dim2 = 3;
    int** mat2 = createMatrix(mat2_vec, dim2);
    std::cout << "Matrix 2 is symmetric: " << (isSymmetric(mat2, dim2) ? "true" : "false") << std::endl;
    deleteMatrix(mat2, dim2);

    // Test Case 3: 1x1 matrix
    std::vector<std::vector<int>> mat3_vec = {
        {10}
    };
    int dim3 = 1;
    int** mat3 = createMatrix(mat3_vec, dim3);
    std::cout << "Matrix 3 is symmetric: " << (isSymmetric(mat3, dim3) ? "true" : "false") << std::endl;
    deleteMatrix(mat3, dim3);

    return 0;
}