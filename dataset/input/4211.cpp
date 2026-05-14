#include <iostream>
#include <string>

void readMatrix(int matrix[3][3], const std::string& name) {
    std::cout << "Enter elements for " << name << " (3x3 matrix):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element at (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[3][3], const std::string& name) {
    std::cout << "Matrix " << name << ":" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrix1[3][3];
    int matrix2[3][3];
    int sumMatrix[3][3];

    readMatrix(matrix1, "A");
    readMatrix(matrix2, "B");

    // Logical error: Performing multiplication instead of addition
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sumMatrix[i][j] = matrix1[i][j] * matrix2[i][j]; // Should be +
        }
    }

    displayMatrix(matrix1, "A");
    displayMatrix(matrix2, "B");
    displayMatrix(sumMatrix, "Sum");

    return 0;
}