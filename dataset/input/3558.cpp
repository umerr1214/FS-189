#include <iostream>

void transposeMatrix(int matrix[3][3], int result[3][3]) {
    // Semantic Error: The function modifies the input 'matrix' in-place,
    // which is not intended as the original matrix should remain unchanged.
    // The problem asks to store the transpose in *another* matrix (result).
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) { // Transpose 'matrix' in-place
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Then copy the *modified* (transposed) 'matrix' to 'result'
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix[i][j];
        }
    }
}

void printMatrix(const int mat[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << mat[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    int originalMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transposedMatrix[3][3];

    transposeMatrix(originalMatrix, transposedMatrix); // originalMatrix is modified here

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(originalMatrix); // Prints the *transposed* originalMatrix
    std::cout << "Transposed Matrix:" << std::endl;
    printMatrix(transposedMatrix); // Prints the transpose (which is the same as modified originalMatrix)

    return 0;
}