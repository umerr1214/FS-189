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
// Correct and efficient implementation using nested loops.
void transposeMatrix(int matrix[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
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