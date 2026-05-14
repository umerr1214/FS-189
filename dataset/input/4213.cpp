#include <iostream>

int main() {
    int matA[3][3];
    int matB[3][3];
    int matSum[3][3];

    std::cout << "Enter elements for Matrix A (3x3):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> matA[i][j];
            // Robustness Issue: No input validation. If user enters non-integer,
            // cin fails, stream enters error state, subsequent reads fail,
            // and uninitialized data might be used.
        }
    }

    std::cout << "\nEnter elements for Matrix B (3x3):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "B[" << i << "][" << j << "]: ";
            std::cin >> matB[i][j];
            // Robustness Issue: No input validation here either.
        }
    }

    // Perform matrix addition
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matSum[i][j] = matA[i][j] + matB[i][j];
        }
    }

    std::cout << "\nResultant Sum Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matSum[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}