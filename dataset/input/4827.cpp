#include <iostream>
#include <array>    // For std::array
#include <numeric>  // For std::accumulate (optional, manual sum is also fine)

int main() {
    // Define matrix dimensions as constants for improved readability, maintainability, and easier modification
    const int ROWS = 3;
    const int COLS = 3;

    // Initialize a 3x3 integer matrix using std::array for fixed-size arrays at compile time.
    // This provides type safety and integrates well with STL algorithms.
    std::array<std::array<int, COLS>, ROWS> matrix = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};

    // Calculate and print the sum of elements in each row separately
    // Using clear, descriptive variable names (row, col, rowSum)
    for (int row = 0; row < ROWS; ++row) {
        int rowSum = 0;
        // Iterate through columns to sum elements of the current row
        for (int col = 0; col < COLS; ++col) {
            rowSum += matrix[row][col];
        }
        // Alternatively, using std::accumulate for conciseness:
        // int rowSum = std::accumulate(matrix[row].begin(), matrix[row].end(), 0);

        // Print the sum for the current row using '\n' for efficiency
        std::cout << "Sum of Row " << row << ": " << rowSum << '\n';
    }

    return 0;
}