#include <iostream>
#include <vector> // Using std::vector for dynamic arrays, or can use fixed-size arrays

// Define constants for matrix dimensions for clarity and maintainability
const int ORIGINAL_ROWS = 2;
const int ORIGINAL_COLS = 3;
const int TRANSPOSED_ROWS = ORIGINAL_COLS; // 3
const int TRANSPOSED_COLS = ORIGINAL_ROWS; // 2

// Function to read matrix elements from user input
void readMatrix(int matrix[ORIGINAL_ROWS][ORIGINAL_COLS]) {
    std::cout << "Enter elements of the " << ORIGINAL_ROWS << "x" << ORIGINAL_COLS << " matrix (" << ORIGINAL_ROWS * ORIGINAL_COLS << " integers):" << std::endl;
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(const int original[ORIGINAL_ROWS][ORIGINAL_COLS], int transposed[TRANSPOSED_ROWS][TRANSPOSED_COLS]) {
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            transposed[j][i] = original[i][j];
        }
    }
}

// Function to print a matrix
// Takes dimensions as arguments to be generic
void printMatrix(const int matrix[], int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            // Using pointer arithmetic for printing generic matrix, or could pass 2D array if dimensions fixed
            // For fixed-size matrices, passing `int matrix[ROWS][COLS]` is more direct.
            // Let's use 2D array specific types for clarity here since dimensions are constants.
            std::cout << matrix[i * num_cols + j] << (j == num_cols - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

// Overload for fixed 2x3 matrix
void printMatrix(const int matrix[ORIGINAL_ROWS][ORIGINAL_COLS]) {
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            std::cout << matrix[i][j] << (j == ORIGINAL_COLS - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

// Overload for fixed 3x2 matrix
void printMatrix(const int matrix[TRANSPOSED_ROWS][TRANSPOSED_COLS]) {
    for (int i = 0; i < TRANSPOSED_ROWS; ++i) {
        for (int j = 0; j < TRANSPOSED_COLS; ++j) {
            std::cout << matrix[i][j] << (j == TRANSPOSED_COLS - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}


// Function containing the core logic, called by main
void solve() {
    int originalMatrix[ORIGINAL_ROWS][ORIGINAL_COLS];
    int transposedMatrix[TRANSPOSED_ROWS][TRANSPOSED_COLS];

    // Read the original matrix
    readMatrix(originalMatrix);

    // Transpose the matrix
    transposeMatrix(originalMatrix, transposedMatrix);

    // Print original matrix
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(originalMatrix);
    std::cout << std::endl; // Extra newline for separation

    // Print transposed matrix
    std::cout << "Transposed Matrix:" << std::endl;
    printMatrix(transposedMatrix);
}

int main() {
    solve();
    return 0;
}