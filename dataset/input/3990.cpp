#include <iostream>
#include <vector>

// Correct `isSymmetric` function
bool isSymmetric(int** matrix, int dimension) {
    if (dimension <= 1) {
        return true;
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

// Helper function to create a dynamic 2D array for testing (NOT USED IN SEMANTIC ERROR CASE)
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

// Helper function to delete a dynamic 2D array (NOT USED IN SEMANTIC ERROR CASE)
void deleteMatrix(int** matrix, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    // SEMANTIC ERROR: Incorrect type conversion when passing a static 2D array to a function expecting int**
    // The `isSymmetric` function expects an `int**` (pointer to a pointer to int),
    // which is typically used for dynamically allocated arrays of pointers.
    // However, here we are passing a static 2D array `static_matrix` by casting its address.
    // `static_matrix` decays to `int (*)[3]` (pointer to an array of 3 ints), not `int**`.
    // This type mismatch leads to undefined behavior when `matrix[i][j]` is accessed inside `isSymmetric`,
    // as the memory layout being dereferenced is not what is expected.

    int static_matrix_1[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    int dim1 = 3;
    // This cast allows compilation but causes semantic error at runtime
    bool result1 = isSymmetric(reinterpret_cast<int**>(static_matrix_1), dim1);
    std::cout << "Matrix 1 (Symmetric) is symmetric: " << (result1 ? "true" : "false") << std::endl;

    int static_matrix_2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int dim2 = 3;
    // This cast allows compilation but causes semantic error at runtime
    bool result2 = isSymmetric(reinterpret_cast<int**>(static_matrix_2), dim2);
    std::cout << "Matrix 2 (Non-symmetric) is symmetric: " << (result2 ? "true" : "false") << std::endl;

    // A correct way to pass a static 2D array to a function expecting `int**` would be to
    // manually construct an array of pointers, or change the function signature.
    // For demonstration, we explicitly show the incorrect usage causing the semantic error.

    return 0;
}