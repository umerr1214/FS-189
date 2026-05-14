#include <iostream>
#include <limits> // Required for numeric_limits

// Function to print a 3x3 matrix with a given title
void printMatrix(const int matrix[3][3], const std::string& title) {
    std::cout << title << ":" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

// Function to transpose a 3x3 integer matrix
// original: The input 3x3 matrix
// transposed: The output 3x3 matrix where the transpose will be stored
void transposeMatrix(int original[3][3], int transposed[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transposed[j][i] = original[i][j];
        }
    }
}

int main() {
    int originalMatrix[3][3];
    int transposedMatrix[3][3];

    std::cout << "Please enter the 9 integer elements of the 3x3 original matrix row by row." << std::endl;
    std::cout << "Example: For a matrix [[1,2,3],[4,5,6],[7,8,9]], enter 1 2 3 4 5 6 7 8 9" << std::endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            while (!(std::cin >> originalMatrix[i][j])) { // Robust input validation
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear(); // Clear the error flag
                // Ignore invalid input up to the end of the line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    // Call the function to transpose the matrix
    transposeMatrix(originalMatrix, transposedMatrix);

    // Print both matrices
    printMatrix(originalMatrix, "Original Matrix");
    printMatrix(transposedMatrix, "Transposed Matrix");

    return 0;
}