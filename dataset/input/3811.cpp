#include <iostream>
#include <vector> // Not strictly necessary for fixed-size arrays, but common for matrix ops

// Function containing the core logic, called by main
void solve() {
    const int ROWS = 2;
    const int COLS = 3;

    int originalMatrix[ROWS][COLS];
    int transposedMatrix[COLS][ROWS];

    std::cout << "Enter elements of the 2x3 matrix (6 integers):" << std::endl;

    // Input original matrix without validation
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cin >> originalMatrix[i][j];
        }
    }

    // Transpose the matrix
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    // Print original matrix
    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << originalMatrix[i][j] << (j == COLS - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // Extra newline for separation

    // Print transposed matrix
    std::cout << "Transposed Matrix:" << std::endl;
    for (int i = 0; i < COLS; ++i) { // Note: COLS rows for transposed
        for (int j = 0; j < ROWS; ++j) { // Note: ROWS columns for transposed
            std::cout << transposedMatrix[i][j] << (j == ROWS - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    solve();
    return 0;
}