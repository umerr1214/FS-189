#include <iostream>
#include <vector>
#include <iomanip> // For std::setw

// Function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int N = matrix.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;

    // Read the input matrix
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Compute transpose into a new matrix
    std::vector<std::vector<int>> transposedMatrix(N, std::vector<int>(N));
    // Semantic Error: The inner loop condition `j <= N` causes out-of-bounds access.
    // Valid indices for a vector of size N are 0 to N-1.
    // When j becomes N, `transposedMatrix[N][i]` and `matrix[i][N]` are accessed,
    // leading to undefined behavior.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= N; ++j) { // Should be 'j < N'
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    printMatrix(transposedMatrix);

    return 0;
}