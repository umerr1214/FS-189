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
// Readability/Efficiency Issue: Hardcoding each element assignment instead of using loops.
// This approach is extremely unreadable, error-prone, and inefficient for larger matrices.
void transposeMatrix(int matrix[3][3], int result[3][3]) {
    // Row 0
    result[0][0] = matrix[0][0];
    result[1][0] = matrix[0][1];
    result[2][0] = matrix[0][2];

    // Row 1
    result[0][1] = matrix[1][0];
    result[1][1] = matrix[1][1];
    result[2][1] = matrix[1][2];

    // Row 2
    result[0][2] = matrix[2][0];
    result[1][2] = matrix[2][1];
    result[2][2] = matrix[2][2];
}

int main() {
    int originalMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transposedMatrix[3][3];

    printMatrix(originalMatrix, "Original Matrix");

    transposeMatrix(originalMatrix, transposedMatrix);

    printMatrix(transposedMatrix, "Transposed Matrix");

    return 0;
}