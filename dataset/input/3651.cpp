#include <iostream> // Required for input/output operations
#include <string>   // Required for std::string

// Function to print a 3x3 matrix to the console with proper formatting.
// Takes a constant reference to a 3x3 integer matrix and a name for printing.
void printMatrix(const int matrix[3][3], const std::string& name) {
    std::cout << name << ":\n"; // Print the matrix name followed by a newline
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j]; // Print the current element
            if (j < 2) { // Add a space after elements, but not after the last one in a row
                std::cout << " ";
            }
        }
        std::cout << '\n'; // Use '\n' for efficient newline (no buffer flush)
    }
}

int main() {
    const int SIZE = 3; // Define matrix size as a constant for clarity and easy modification

    // Declare and initialize the first 3x3 integer matrix with example data
    int matrixA[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Declare the second 3x3 integer matrix
    int matrixB[SIZE][SIZE];
    // Populate matrixB with example data (decreasing pattern)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrixB[i][j] = 9 - (i * SIZE + j); // Example: 9 8 7, 6 5 4, 3 2 1
        }
    }

    // Declare the matrix to store the sum of matrixA and matrixB
    int sumMatrix[SIZE][SIZE];

    // Perform matrix addition: sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j]
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print the resulting sum matrix using the helper function
    printMatrix(sumMatrix, "Sum Matrix");

    return 0; // Indicate successful execution
}