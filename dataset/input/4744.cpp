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
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            transposedMatrix[j][i] = matrix[i][j] // Syntax Error: Missing semicolon
        }
    }

    // Print the transposed matrix
    printMatrix(transposedMatrix);

    return 0;
}