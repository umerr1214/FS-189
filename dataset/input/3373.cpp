#include <iostream>
#include <iomanip> // For std::setw

int main() {
    const int ROWS = 3;
    const int COLS = 3;

    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int C[ROWS][COLS];

    std::cout << "Enter elements for Matrix A (3x3):" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << "Enter element A[" << i << "][" << j << "]: ";
            // Robustness Issue: No input validation.
            // If a non-integer is entered, cin.fail() will be true,
            // and the loop will likely get stuck in an infinite loop
            // trying to read the same bad input, or use garbage values.
            std::cin >> A[i][j];
        }
    }

    std::cout << "\nEnter elements for Matrix B (3x3):" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << "Enter element B[" << i << "][" << j << "]: ";
            // Robustness Issue: No input validation here either.
            std::cin >> B[i][j];
        }
    }

    // Compute sum C = A + B
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print Matrix A
    std::cout << "\nMatrix A:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << A[i][j];
        }
        std::cout << std::endl;
    }

    // Print Matrix B
    std::cout << "\nMatrix B:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << B[i][j];
        }
        std::cout << std::endl;
    }

    // Print Matrix C
    std::cout << "\nMatrix C (Sum A + B):" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << C[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}