#include <iostream>
#include <vector>

// Function containing the solution logic, renamed from main for testing purposes.
// It returns an integer to indicate success (0) or failure (non-zero).
int solution_logic() {
    // Readability / Efficiency Issue: No fast I/O setup
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int n; // Readability Issue: Poor variable name 'n' instead of 'matrixSize' or 'dimension'
    std::cin >> n;

    // Basic check for non-positive dimension, not the focus of this error type.
    // If n <= 0, vectors will be empty and loops won't run, resulting in empty output, which is functionally correct.
    if (n <= 0) {
        // No specific error message, just proceeds to print an empty matrix (empty output).
    }

    // Readability Issue: Poor variable name 'm' for the original matrix
    std::vector<std::vector<int>> m(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> m[i][j];
        }
    }

    // Efficiency Issue: Redundant memory allocation and copy operation
    // Creating a temporary matrix and copying elements unnecessarily.
    // This adds an O(N^2) operation and extra memory usage without benefit.
    // Readability Issue: Poor variable name 't_orig' and inconsistent loop variables
    std::vector<std::vector<int>> t_orig(n, std::vector<int>(n)); 
    for (int r = 0; r < n; ++r) { // 'r' and 'c' are acceptable but 'i' and 'j' are more common for matrix indices
        for (int c = 0; c < n; ++c) {
            t_orig[r][c] = m[r][c]; // Unnecessary copy: original 'm' could be used directly
        }
    }

    // Readability Issue: Poor variable name 'tr' for the transposed matrix
    // Compute transpose into another new matrix from the redundant copy
    std::vector<std::vector<int>> tr(n, std::vector<int>(n)); 
    for (int x = 0; x < n; ++x) { // Readability Issue: Unconventional loop variables 'x' and 'y'
        for (int y = 0; y < n; ++y) {
            tr[y][x] = t_orig[x][y]; // Transpose from the temporary copy 't_orig'
        }
    }

    // Print result
    // Readability Issue: Poor variable names 'a' and 'b' for loop indices
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            std::cout << tr[a][b] << (b == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0; // Indicate successful execution
}

int main() {
    return solution_logic();
}