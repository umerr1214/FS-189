#include <iostream>
#include <string> // Required for std::string

const int ROWS = 3; // Define matrix dimensions as constants for maintainability
const int COLS = 3;

// Function to get matrix input from user
void getMatrixInput(int matrix[ROWS][COLS], const std::string& matrixName) {
    std::cout << "Enter elements for " << matrixName << " (" << ROWS << "x" << COLS << "):" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrixName << "[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
            // For this 'Correct Version', we assume valid integer input as per problem scope.
            // Robust error handling for invalid input would be in a different category.
        }
    }
}

// Function to add two matrices and store the result in a third
void addMatrices(const int matrixA[ROWS][COLS], const int matrixB[ROWS][COLS], int sumMatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(const int matrix[ROWS][COLS], const std::string& matrixName) {
    std::cout << "\n" << matrixName << ":" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t"; // Use tab for clear alignment
        }
        std::cout << std::endl; // Newline after each row
    }
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int sumResult[ROWS][COLS];

    // Get input for both matrices
    getMatrixInput(matrix1, "Matrix A");
    getMatrixInput(matrix2, "Matrix B");

    // Perform matrix addition
    addMatrices(matrix1, matrix2, sumResult);

    // Display all matrices
    displayMatrix(matrix1, "Matrix A");
    displayMatrix(matrix2, "Matrix B");
    displayMatrix(sumResult, "Sum Matrix");

    return 0;
}