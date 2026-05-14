#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));

    // Input matrix elements
    std::cout << "Enter 9 integer elements for the 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate and print row sums
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0;
        // Semantic Error: The inner loop condition 'j <= 3' causes an out-of-bounds access.
        // For a 3x3 matrix, valid column indices are 0, 1, 2. When j becomes 3,
        // 'matrix[i][j]' attempts to access 'matrix[i][3]', which is outside the allocated memory for the row.
        // This leads to undefined behavior (e.g., crash, corrupted data, incorrect sums).
        for (int j = 0; j <= 3; ++j) { // Should be 'j < 3'
            rowSum += matrix[i][j];
        }
        std::cout << "Sum of row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}