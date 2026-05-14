#include <iostream>
#include <vector>
#include <string> // Required for std::to_string in driver

// Function with readability/efficiency issue: passes matrix by value and performs redundant checks.
bool isSymmetric(std::vector<std::vector<int>> matrix, int dim) { // Passed by value (efficiency issue)
    // An empty matrix (dim=0) is considered symmetric.
    if (dim == 0) {
        return true;
    }

    // Readability/Efficiency Issue 1: The input matrix is passed by value,
    // which creates a full copy of the matrix. For large matrices, this is
    // very inefficient in terms of both time and memory. It should be passed by const reference.

    // Readability/Efficiency Issue 2: The nested loops iterate over the entire N*N matrix.
    // This leads to redundant checks:
    // - It checks matrix[i][j] == matrix[j][i] and later also checks matrix[j][i] == matrix[i][j].
    //   Only one of these pairs (e.g., for j > i) is sufficient.
    // - It checks matrix[i][i] == matrix[i][i] for all diagonal elements, which is always true and unnecessary.
    // A more efficient approach would iterate only over the upper or lower triangle of the matrix.
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) { // Iterates N*N times
            if (matrix[i][j] != matrix[j][i]) { // Redundant checks
                return false;
            }
        }
    }
    return true;
}

// Helper function to convert matrix to string for output
std::string matrixToString(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) return "[]";
    std::string s = "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        s += "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            s += std::to_string(matrix[i][j]);
            if (j < matrix[i].size() - 1) {
                s += ", ";
            }
        }
        s += "]";
        if (i < matrix.size() - 1) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

int main() {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> test_matrices = {
        {{{1, 2, 3}, {2, 4, 5}, {3, 5, 6}}, 3}, // Symmetric 3x3
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 3}, // Non-symmetric 3x3
        {{{1, 2}, {2, 1}}, 2},                 // Symmetric 2x2
        {{{1, 2}, {3, 4}}, 2},                 // Non-symmetric 2x2
        {{{5}}, 1},                            // 1x1 matrix (symmetric)
        {{}, 0},                               // Empty matrix (symmetric)
        {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}, 4}, // Larger symmetric
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 4} // Larger non-symmetric
    };

    std::vector<bool> expected_results = {
        true, false, true, false, true, true, true, false
    };

    for (size_t i = 0; i < test_matrices.size(); ++i) {
        const auto& matrix_pair = test_matrices[i];
        const auto& matrix = matrix_pair.first;
        int dim = matrix_pair.second;
        bool result = isSymmetric(matrix, dim); // Note: matrix is copied here due to pass-by-value
        std::cout << "Test Case " << (i + 1) << ":\n";
        std::cout << "  Input Matrix: " << matrixToString(matrix) << ", Dim: " << dim << "\n";
        std::cout << "  Expected: " << (expected_results[i] ? "true" : "false") << "\n";
        std::cout << "  Got: " << (result ? "true" : "false") << "\n";
        if (result == expected_results[i]) {
            std::cout << "  Result: PASSED\n";
        } else {
            std::cout << "  Result: FAILED\n";
        }
        std::cout << "---------------------\n";
    }

    // Additional test for larger matrix to highlight potential efficiency issues
    std::cout << "\n--- Efficiency Test (Large Matrix) ---\n";
    const int large_dim = 100;
    std::vector<std::vector<int>> large_matrix(large_dim, std::vector<int>(large_dim));
    for(int i = 0; i < large_dim; ++i) {
        for(int j = 0; j < large_dim; ++j) {
            large_matrix[i][j] = i + j; // Creates a symmetric matrix
        }
    }
    std::cout << "  Input Matrix: Large " << large_dim << "x" << large_dim << " symmetric matrix\n";
    std::cout << "  Expected: true\n";
    bool large_result = isSymmetric(large_matrix, large_dim); // This will involve a large copy
    std::cout << "  Got: " << (large_result ? "true" : "false") << "\n";
    if (large_result) {
        std::cout << "  Result: PASSED (Correct, but potentially slow due to copying the large matrix)\n";
    } else {
        std::cout << "  Result: FAILED\n";
    }
    std::cout << "---------------------\n";

    return 0;
}