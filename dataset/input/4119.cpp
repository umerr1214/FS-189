#include <iostream>
#include <limits> // Required for numeric_limits to clear input buffer
#include <string>   // Required for std::string

// Function to read a 2x2 matrix from user input with validation
void readMatrix(int matrix[2][2], const std::string& matrixName) {
    std::cout << "Enter elements for " << matrixName << " (2x2):" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            while (true) { // Loop until valid integer input is received
                std::cout << "Enter element " << matrixName << "[" << i << "][" << j << "]: ";
                std::cin >> matrix[i][j];

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter an integer.\n";
                    std::cin.clear(); // Clear the error flag
                    // Ignore the rest of the invalid input line
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    break; // Valid input, exit loop
                }
            }
        }
    }
    std::cout << std::endl; // Add an extra newline for better spacing after input
}

// Function to print a 2x2 matrix in a clear format
void printMatrix(const int matrix[2][2], const std::string& matrixName) {
    std::cout << matrixName << ":" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << matrix[i][j] << "\t"; // Use tab for clear and consistent spacing
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // Add an extra newline for better spacing between matrices
}

int main() {
    int matrixA[2][2];
    int matrixB[2][2];
    int matrixSum[2][2]; // To store the result of addition

    // Read elements for Matrix A using a dedicated function
    readMatrix(matrixA, "Matrix A");

    // Read elements for Matrix B using a dedicated function
    readMatrix(matrixB, "Matrix B");

    // Perform matrix addition
    // The loop iterates through each element and calculates the sum
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print all three matrices using a dedicated function for clear output
    printMatrix(matrixA, "Matrix A");
    printMatrix(matrixB, "Matrix B");
    printMatrix(matrixSum, "Matrix C (Sum)"); // As per question, the result is the third matrix

    return 0;
}