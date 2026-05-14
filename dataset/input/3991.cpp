#include <iostream>
#include <vector>
#include <string> // Required for std::to_string in driver

// Function with robustness issue: does not validate 'dim' against actual matrix dimensions.
// If 'dim' is larger than the actual matrix dimensions,
// accessing matrix.at(i).at(j) or matrix.at(j).at(i) will throw std::out_of_range.
bool isSymmetric(const std::vector<std::vector<int>>& matrix, int dim) {
    // An empty matrix (dim=0) is considered symmetric.
    if (dim == 0) {
        return true;
    }

    // Robustness Issue: The function assumes 'dim' accurately reflects the matrix's actual dimensions
    // (matrix.size() and matrix[i].size()) without performing any checks.
    // If 'dim' is provided as a value larger than the actual matrix dimensions,
    // accessing elements using 'matrix.at(i).at(j)' or 'matrix.at(j).at(i)' will lead to
    // an std::out_of_range exception, indicating a lack of robustness for inconsistent inputs.
    // For example, if matrix is 2x2 but dim is passed as 3, it will try to access matrix.at(2), causing a crash.

    for (int i = 0; i < dim; ++i) {
        for (int j = i + 1; j < dim; ++j) {
            // Using .at() to explicitly throw std::out_of_range on out-of-bounds access
            // if 'dim' is larger than the actual matrix dimensions.
            if (matrix.at(i).at(j) != matrix.at(j).at(i)) {
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

    // --- Robustness Test Case: Triggering the issue ---
    std::cout << "\n--- Robustness Issue Test Case ---\n";
    std::vector<std::vector<int>> robust_matrix = {{1, 2}, {3, 4}}; // A 2x2 matrix
    int robust_dim = 3; // But we claim it's a 3x3 matrix
    std::cout << "  Input Matrix: " << matrixToString(robust_matrix) << ", Dim: " << robust_dim << "\n";
    std::cout << "  Expected: false (if it didn't crash, it would be non-symmetric)\n";
    std::cout << "  This test is designed to expose a robustness issue.\n";
    std::cout << "  The program is expected to terminate with an std::out_of_range exception ";
    std::cout << "due to 'dim' being larger than the actual matrix dimensions.\n";
    try {
        bool result = isSymmetric(robust_matrix, robust_dim); // This line is expected to throw
        std::cout << "  Got: " << (result ? "true" : "false") << "\n";
        std::cout << "  Result: FAILED (Expected crash/exception, but got a result)\n";
    } catch (const std::out_of_range& e) {
        std::cout << "  Caught exception: " << e.what() << "\n";
        std::cout << "  Result: PASSED (Program behaved as expected for robustness issue - caught std::out_of_range)\n";
    } catch (...) {
        std::cout << "  Caught unknown exception.\n";
        std::cout << "  Result: PASSED (Program behaved as expected for robustness issue - caught an exception)\n";
    }
    std::cout << "---------------------\n";

    return 0;
}