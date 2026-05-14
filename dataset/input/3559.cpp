#include <iostream>
#include <cstdio> // For printf

// Function to print a 3x3 matrix
void printMatrix(const int matrix[3][3], const char* name) {
    printf("%s:\n", name);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to transpose a 3x3 matrix
void transposeMatrix(int matrix[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    // Robustness Issue: Unintended side-effect - modifying the input matrix.
    // This could lead to unexpected behavior if the caller expects 'matrix' to remain unchanged.
    matrix[0][0] = 0; // Modifying an element of the original matrix
}

int main() {
    int originalMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transposedMatrix[3][3];

    printMatrix(originalMatrix, "Original Matrix"); // Print original BEFORE transpose call

    transposeMatrix(originalMatrix, transposedMatrix);

    // If printMatrix(originalMatrix, "Original Matrix"); was called here,
    // matrix[0][0] would be 0, demonstrating the robustness issue.
    // For this problem, the 'result' is correct, but the function itself has a robustness flaw.

    printMatrix(transposedMatrix, "Transposed Matrix");

    return 0;
}