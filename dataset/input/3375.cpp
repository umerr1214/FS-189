#include <iostream>
#include <iomanip> // For std::setw
#include <limits>  // For std::numeric_limits

int main() {
    const int MATRIX_SIZE = 3; // Use a named constant for matrix dimensions

    int matrixA[MATRIX_SIZE][MATRIX_SIZE];
    int matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int matrixC[MATRIX_SIZE][MATRIX_SIZE];

    // Function to read a matrix with input validation
    auto readMatrix = [&](const std::string& name, int (&matrix)[MATRIX_SIZE][MATRIX_SIZE]) {
        std::cout << "Enter elements for Matrix " << name << " (" << MATRIX_SIZE << "x" << MATRIX_SIZE << "):" << std::endl;
        for (int row = 0; row < MATRIX_SIZE; ++row) {
            for (int col = 0; col < MATRIX_SIZE; ++col) {
                while (true) { // Loop until valid input is received
                    std::cout << "Enter element " << name << "[" << row << "][" << col << "]: ";
                    std::cin >> matrix[row][col];

                    if (std::cin.fail()) {
                        std::cout << "Invalid input. Please enter an integer." << std::endl;
                        std::cin.clear(); // Clear the error flag
                        // Discard invalid input from the buffer up to the newline character
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        break; // Valid input, exit loop
                    }
                }
            }
        }
    };

    // Function to print a matrix
    auto printMatrix = [&](const std::string& name, const int (&matrix)[MATRIX_SIZE][MATRIX_SIZE]) {
        std::cout << "\n" << name << ":" << std::endl;
        for (int row = 0; row < MATRIX_SIZE; ++row) {
            for (int col = 0; col < MATRIX_SIZE; ++col) {
                std::cout << std::setw(4) << matrix[row][col]; // Clear formatting with setw
            }
            std::cout << std::endl;
        }
    };

    // Read Matrix A
    readMatrix("A", matrixA);

    // Read Matrix B
    readMatrix("B", matrixB);

    // Compute sum C = A + B
    for (int row = 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            matrixC[row][col] = matrixA[row][col] + matrixB[row][col];
        }
    }

    // Print all three matrices
    printMatrix("Matrix A", matrixA);
    printMatrix("Matrix B", matrixB);
    printMatrix("Matrix C (Sum A + B)", matrixC);

    return 0;
}