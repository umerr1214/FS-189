#include <iostream>

void transposeMatrix(int original[3][3], int transposed[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transposed[i][j] = original[i][j]; // Logical Error: Should be original[j][i] for transpose
        }
    }
}

void printMatrix(const int matrix[3][3], const char* title) {
    std::cout << title << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    int original[3][3];
    int transposed[3][3];

    std::cout << "Enter elements of the 3x3 matrix (9 integers):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> original[i][j];
        }
    }

    transposeMatrix(original, transposed);

    printMatrix(original, "Original Matrix:");
    std::cout << std::endl;
    printMatrix(transposed, "Transposed Matrix:"); // This will incorrectly print a copy of the original

    return 0;
}