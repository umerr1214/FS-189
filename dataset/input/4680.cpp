#include <iostream>
#include <vector>

long long calculateSum(const std::vector<std::vector<int>>& matrix) {
    long long totalSum = 0;
    // Semantic error: The loop condition `i <= matrix.size()` allows `i` to become `matrix.size()`.
    // When `i` is `matrix.size()`, accessing `matrix[i]` is an out-of-bounds operation,
    // leading to undefined behavior (e.g., crash, memory corruption, or incorrect sum).
    for (int i = 0; i <= matrix.size(); ++i) {
        // Assuming matrix is not empty and has a consistent number of columns.
        // If matrix is empty, matrix[0].size() would also be an issue, but the primary UB is matrix[i].
        if (!matrix.empty()) { // Guard against empty matrix for matrix[0].size() access
            for (int j = 0; j < matrix[0].size(); ++j) { // Accessing matrix[i] where i can be out of bounds
                totalSum += matrix[i][j]; // This line triggers undefined behavior when i == matrix.size()
            }
        }
    }
    return totalSum;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    long long sum = calculateSum(matrix);
    std::cout << sum << std::endl;

    return 0;
}