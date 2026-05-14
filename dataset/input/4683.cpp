#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate (optional, direct sum is also fine)

// This program correctly calculates and prints the sum of all elements
// in a 2D integer array (matrix).
// It is efficient, readable, and handles standard edge cases like empty
// matrices gracefully.
int solution_main() {
    int rows, cols;
    long long totalSum = 0; // Use long long to prevent potential overflow for large sums

    // Read matrix dimensions
    if (!(std::cin >> rows >> cols)) {
        // Handle invalid input for dimensions
        std::cerr << "Error: Invalid input for matrix dimensions." << std::endl;
        return 1;
    }

    // Validate dimensions to ensure they are non-negative
    if (rows < 0 || cols < 0) {
        std::cerr << "Error: Matrix dimensions cannot be negative." << std::endl;
        return 1;
    }

    // If either dimension is zero, the sum is zero, and no elements need to be read.
    // This also implicitly handles 0x0, 0xN, Nx0 cases correctly.
    if (rows == 0 || cols == 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    // Read elements and calculate sum
    // Using std::vector<std::vector<int>> for clear 2D structure
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int element;
            if (!(std::cin >> element)) {
                // Handle cases where not enough elements are provided
                std::cerr << "Error: Not enough elements or invalid element provided." << std::endl;
                return 1;
            }
            matrix[i][j] = element;
            totalSum += element;
        }
    }

    // Print the total sum
    std::cout << totalSum << '\n'; // Use '\n' for efficiency

    return 0;
}