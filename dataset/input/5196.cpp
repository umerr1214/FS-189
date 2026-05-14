#include <iostream>

void transposeMatrix(int original[3][3], int transposed[3][3]) {
    // Semantic Error: Loop iterates out of bounds. 'i' will go from 0 to 3, accessing index 3.
    for (int i = 0; i <= 3; ++i) { // Should be i < 3
        for (int j = 0; j < 3; ++j) {
            // Accesses original[j][i] and transposed[i][j]. When i=3, this is out of bounds for a 3x3 matrix.
            transposed[i][j] = original[j][i];
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

    transposeMatrix(original, transposed); // This call will cause out-of-bounds access leading to undefined behavior

    printMatrix(original, "Original Matrix:");
    std::cout << std::endl;
    printMatrix(transposed, "Transposed Matrix:");

    return 0;
}