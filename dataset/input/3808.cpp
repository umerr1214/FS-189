#include <iostream>
#include <vector>

const int ORIGINAL_ROWS = 2;
const int ORIGINAL_COLS = 3;
const int TRANSPOSED_ROWS = 3;
const int TRANSPOSED_COLS = 2;

void solution_main() {
    int originalMatrix[ORIGINAL_ROWS][ORIGINAL_COLS];
    int transposedMatrix[TRANSPOSED_ROWS][TRANSPOSED_COLS];

    std::cout << "Enter elements of the 2x3 matrix:\n";
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            std::cin >> originalMatrix[i][j];
        }
    }

    std::cout << "Original Matrix:\n" // SYNTAX ERROR: Missing semicolon
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            std::cout << originalMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Transpose the matrix
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    std::cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < TRANSPOSED_ROWS; ++i) {
        for (int j = 0; j < TRANSPOSED_COLS; ++j) {
            std::cout << transposedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    solution_main();
    return 0;
}