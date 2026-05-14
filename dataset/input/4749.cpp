#include <iostream>
#include <vector>

// Function containing the solution logic, renamed from main for testing purposes.
// It returns an integer to indicate success (0) or failure (non-zero).
int solution_logic() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int matrixSize; // Clear variable name for the dimension of the square matrix
    std::cin >> matrixSize;

    // Handle edge case: non-positive dimension.
    // The problem states "Given a square 2D integer array", implying matrixSize > 0.
    // For matrixSize <= 0, we gracefully return without processing or printing anything.
    if (matrixSize <= 0) {
        return 0; // No matrix to transpose, so return successfully without output.
    }

    // Declare and initialize the original matrix using std::vector<std::vector<int>>
    // This provides robust and automatic memory management.
    std::vector<std::vector<int>> originalMatrix(matrixSize, std::vector<int>(matrixSize));

    // Read elements into the original matrix
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cin >> originalMatrix[i][j];
        }
    }

    // Declare and initialize the transposed matrix
    // It will have the same dimensions as the original for a square matrix.
    std::vector<std::vector<int>> transposedMatrix(matrixSize, std::vector<int>(matrixSize));

    // Compute the transpose: swap rows and columns
    // The element at originalMatrix[i][j] moves to transposedMatrix[j][i].
    // This is an efficient O(N^2) operation for an N x N matrix.
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            // Print element followed by a space, unless it's the last element in the row
            std::cout << transposedMatrix[i][j] << (j == matrixSize - 1 ? "" : " ");
        }
        std::cout << "\n"; // Newline after each row for proper formatting
    }

    return 0; // Indicate successful execution
}

int main() {
    return solution_logic();
}