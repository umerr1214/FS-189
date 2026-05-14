#include <iostream>
#include <vector>
#include <string> // Not strictly needed for this problem, but often included

// Function containing the solution logic, renamed from main for testing purposes.
// It returns an integer to indicate success (0) or failure (non-zero).
int solution_logic() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; // Variable to store the dimension of the square matrix
    std::cin >> N;

    // Robustness Issue: Handling non-positive dimension
    // The problem states "Given a square 2D integer array", implying N > 0.
    // A robust program should handle cases where N is zero or negative gracefully.
    if (N <= 0) {
        std::cout << "Error: Matrix dimension must be a positive integer.\n";
        return 1; // Indicate an error occurred
    }

    // Declare and initialize the original matrix using std::vector<std::vector<int>>
    // This provides automatic memory management.
    std::vector<std::vector<int>> originalMatrix(N, std::vector<int>(N));

    // Read elements into the original matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Robustness Issue: Check if input reading fails (e.g., EOF, non-integer input)
            if (!(std::cin >> originalMatrix[i][j])) {
                std::cout << "Error: Failed to read matrix element. Input might be incomplete or invalid.\n";
                return 1; // Indicate an error occurred
            }
        }
    }

    // Declare and initialize the transposed matrix
    // It will have the same dimensions as the original for a square matrix.
    std::vector<std::vector<int>> transposedMatrix(N, std::vector<int>(N));

    // Compute the transpose: swap rows and columns
    // The element at originalMatrix[i][j] moves to transposedMatrix[j][i]
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << transposedMatrix[i][j] << (j == N - 1 ? "" : " ");
        }
        std::cout << "\n"; // Newline after each row
    }

    return 0; // Indicate successful execution
}

int main() {
    return solution_logic();
}