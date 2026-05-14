#include <iostream>
#include <vector>

const int ORIGINAL_ROWS = 2;
const int ORIGINAL_COLS = 3;
// Correct dimensions for transposed matrix would be TRANSPOSED_ROWS=3, TRANSPOSED_COLS=2
// These are intentionally omitted or incorrectly used to cause a semantic error.

void solution_main() {
    int originalMatrix[ORIGINAL_ROWS][ORIGINAL_COLS];
    // SEMANTIC ERROR: Declaring transposedMatrix with incorrect dimensions (2x3 instead of 3x2).
    // This will lead to an array out-of-bounds write when attempting to store transposed elements.
    int transposedMatrix[ORIGINAL_ROWS][ORIGINAL_COLS]; // Should be [ORIGINAL_COLS][ORIGINAL_ROWS]

    std::cout << "Enter elements of the 2x3 matrix:\n";
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            std::cin >> originalMatrix[i][j];
        }
    }

    std::cout << "Original Matrix:\n";
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            std::cout << originalMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Transpose the matrix
    for (int i = 0; i < ORIGINAL_ROWS; ++i) {
        for (int j = 0; j < ORIGINAL_COLS; ++j) {
            // Semantic Error: 'j' goes up to ORIGINAL_COLS-1 (which is 2).
            // For transposedMatrix[ORIGINAL_ROWS][ORIGINAL_COLS] (i.e., [2][3]),
            // accessing transposedMatrix[2][i] is out of bounds (valid indices for first dim are 0, 1).
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    std::cout << "\nTransposed Matrix:\n";
    // This printing loop will also likely cause issues or print garbage
    // due to the preceding out-of-bounds write.
    for (int i = 0; i < ORIGINAL_COLS; ++i) { // Should be TRANSPOSED_ROWS (3)
        for (int j = 0; j < ORIGINAL_ROWS; ++j) { // Should be TRANSPOSED_COLS (2)
            std::cout << transposedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    solution_main();
    return 0;
}