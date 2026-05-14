#include <iostream>
#include <array>    // For std::array for fixed-size matrices
#include <vector>   // For std::vector to store sums

int main() {
    // Define matrix dimensions using constants for robustness and readability
    const int ROWS = 3;
    const int COLS = 3;

    // Initialize a 3x3 integer matrix with hardcoded values using std::array for type safety
    std::array<std::array<int, COLS>, ROWS> matrix = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};

    // Vectors to store row and column sums, initialized to zero
    std::vector<int> rowSums(ROWS, 0);
    std::vector<int> colSums(COLS, 0);

    // Calculate row and column sums in a single pass for efficiency
    for (int i = 0; i < ROWS; ++i) { // 'i' represents row index
        for (int j = 0; j < COLS; ++j) { // 'j' represents column index
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
        }
    }

    // Print row sums
    std::cout << "Calculating row sums:\n";
    for (int i = 0; i < ROWS; ++i) {
        std::cout << "Row " << i << " sum: " << rowSums[i] << "\n";
    }

    // Print column sums
    std::cout << "Calculating column sums:\n";
    for (int j = 0; j < COLS; ++j) {
        std::cout << "Column " << j << " sum: " << colSums[j] << "\n";
    }

    return 0;
}