#include <iostream>
#include <array>    // For std::array
#include <iomanip>  // For std::setw

int main() {
    // Define constants for matrix dimensions for better readability and maintainability
    const int ROWS = 3;
    const int COLS = 3;

    // Declare and initialize a 3x3 integer matrix using std::array
    // std::array provides fixed-size array benefits with container-like features,
    // and ensures compile-time size checking.
    std::array<std::array<int, COLS>, ROWS> matrix = {
        {{1, 2, 3}},
        {{10, 20, 30}},
        {{100, 200, 300}}
    };

    // Print the matrix in a formatted way
    // Using clear loop variables, constants for dimensions,
    // and std::setw for consistent alignment, followed by '\n' for efficiency.
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Using std::setw(5) to accommodate up to 4-digit numbers with a space,
            // making the formatting more robust for a reasonable range of integer values.
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << '\n'; // Use '\n' instead of std::endl for potentially better performance (avoids flushing on each newline)
    }

    return 0;
}