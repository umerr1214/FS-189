#include <iostream>

// Renaming main to avoid conflicts with a potential testing framework driver
int main_user_code() {
    int A[3][3], B[3][3], C[3][3];

    std::cout << "Enter elements for Matrix A (3x3):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Enter elements for Matrix B (3x3):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> B[i][j];
        }
    }

    // Compute sum
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print Matrix A
    std::cout << "\nMatrix A:" << std::endl // SYNTAX ERROR: Missing semicolon here
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << A[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }

    // Print Matrix B
    std::cout << "\nMatrix B:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << B[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }

    // Print Matrix C (Sum)
    std::cout << "\nMatrix C (Sum):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << C[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}