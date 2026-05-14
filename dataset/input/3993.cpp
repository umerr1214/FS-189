#include <iostream>
#include <vector>
#include <string> // Required for std::to_string in driver

// Correct and efficient function to check if a matrix is symmetric.
bool isSymmetric(const std::vector<std::vector<int>>& matrix, int dim) {
    // An empty matrix (dim=0) is considered symmetric.
    if (dim == 0) {
        return true;
    }

    // According to the problem statement, the input is a "square 2D integer array (matrix)
    // and its dimension". This implies matrix.size() == dim and matrix[i].size() == dim.
    // Therefore, explicit checks for matrix.size() and matrix[i].size() against 'dim'
    // are not strictly required for correctness under the problem's assumptions of valid input.
    // The loops below correctly handle a 1x1 matrix as well (the inner loop condition j < dim
    // will be 1 < 1, which is false, so the inner loop won't run, correctly returning true).

    // The matrix is passed by const reference, avoiding unnecessary copies (efficient).
    // The loops iterate only through the upper triangle (excluding the diagonal),
    // performing each necessary comparison exactly once (efficient).
    for (int i = 0; i < dim; ++i) {
        for (int j = i + 1; j < dim; ++j) { // Iterate only over the upper triangle
            if (matrix[i][j] != matrix[j][i]) {
                return false; // Found a non-symmetric pair
            }
        }
    }
    return true; // All checked pairs are symmetric
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
        bool result = isSymmetric(matrix, dim);
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

    return 0;
}