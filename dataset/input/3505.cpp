#include <iostream>
#include <iomanip> // For std::setw

int main() {
    // Declare and initialize a 3x3 integer matrix (C-style array)
    int matrix[3][3] = {
        {1, 2, 3},
        {10, 20, 30},
        {100, 200, 300}
    };

    // Print the matrix in a formatted way
    // Robustness Issue: Hardcoded dimensions '3' in loops,
    // and fixed std::setw(4) which might not be enough for larger numbers (e.g., 5-digit integers),
    // causing misalignment and breaking the "formatted way" requirement.
    // This makes the output formatting fragile to data variations.
    for (int i = 0; i < 3; ++i) { // Hardcoded '3'
        for (int j = 0; j < 3; ++j) { // Hardcoded '3'
            std::cout << std::setw(4) << matrix[i][j]; // Fixed width, potentially not robust
        }
        std::cout << std::endl; // Using std::endl which flushes, not an issue for this small case but can be less efficient
    }

    return 0;
}