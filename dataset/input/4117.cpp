#include <iostream>

int main() {
    int matrixA[2][2];
    int matrixB[2][2];
    int matrixC[2][2]; // To store the result

    std::cout << "Enter elements for Matrix A (2x2):" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "Enter element A[" << i << "][" << j << "]: ";
            std::cin >> matrixA[i][j]; // Robustness issue: no input validation
        }
    }

    std::cout << "\nEnter elements for Matrix B (2x2):" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "Enter element B[" << i << "][" << j << "]: ";
            std::cin >> matrixB[i][j]; // Robustness issue: no input validation
        }
    }

    // Perform matrix addition
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print Matrix A
    std::cout << "\nMatrix A:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << matrixA[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Print Matrix B
    std::cout << "\nMatrix B:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << matrixB[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Print Matrix C (Sum)
    std::cout << "\nMatrix C (Sum):" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << matrixC[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}