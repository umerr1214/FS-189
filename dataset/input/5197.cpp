#include <iostream>
#include <vector> // Not strictly needed for fixed-size arrays, but common header

// Function to print a 3x3 matrix
void printMatrix(const int matrix[3][3], const std::string& title) {
    std::cout << title << ":" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

// Function to transpose a 3x3 matrix
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

    std::cout << "Enter the 9 elements of the 3x3 original matrix row by row:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> originalMatrix[i][j];
            // NO INPUT VALIDATION: If a non-integer is entered, cin will fail
            // and subsequent reads will also fail, leading to an infinite loop
            // or incorrect data if not handled.
        }
    }

    transposeMatrix(originalMatrix, transposedMatrix);

    printMatrix(originalMatrix, "Original Matrix");
    printMatrix(transposedMatrix, "Transposed Matrix");

    return 0;
}