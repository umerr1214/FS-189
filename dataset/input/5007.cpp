#include <iostream>
#include <vector>
#include <algorithm> // For std::min

// Correct, efficient, and robust version of searchMatrix.
// - Takes the matrix by const reference to avoid unnecessary copying.
// - Iterates directly over the 2D structure, which is efficient.
// - Robustly handles empty matrices, zero dimensions, and even non-rectangular matrices
//   or cases where provided 'rows'/'cols' might be inconsistent with actual matrix size.
bool searchMatrix(const std::vector<std::vector<int>>& matrix, int rows, int cols, int target) {
    // Robustness checks for overall matrix and provided dimensions.
    // If the matrix itself is empty, or the logical search dimensions are zero,
    // the target cannot be found.
    if (rows <= 0 || cols <= 0 || matrix.empty()) {
        return false;
    }

    // Determine the actual iteration bounds, taking the minimum of provided dimensions
    // and the actual vector sizes to prevent out-of-bounds access.
    // This makes the function robust against incorrect 'rows' or 'cols' parameters
    // that might be larger than the actual matrix dimensions, or if the matrix
    // itself is smaller than indicated by `rows`/`cols`.
    int effective_rows = std::min(rows, (int)matrix.size());

    for (int i = 0; i < effective_rows; ++i) {
        // Handle rows that might be empty or shorter than 'cols' parameter.
        // Again, take the minimum of provided 'cols' and the actual row size.
        // This also gracefully handles non-rectangular matrices where rows might have different lengths.
        int effective_cols = std::min(cols, (int)matrix[i].size());
        for (int j = 0; j < effective_cols; ++j) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Test cases for correctness and robustness

    // 1. Standard cases - target found
    std::vector<std::vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Target 5 in m1 (3x3): " << (searchMatrix(m1, 3, 3, 5) ? "true" : "false") << std::endl;        // Expected: true

    // 2. Standard cases - target not found
    std::cout << "Target 10 in m1 (3x3): " << (searchMatrix(m1, 3, 3, 10) ? "true" : "false") << std::endl;       // Expected: false

    // 3. Single element matrix - target found
    std::vector<std::vector<int>> m2 = {{10}};
    std::cout << "Target 10 in m2 (1x1): " << (searchMatrix(m2, 1, 1, 10) ? "true" : "false") << std::endl;     // Expected: true

    // 4. Single element matrix - target not found
    std::cout << "Target 1 in m2 (1x1): " << (searchMatrix(m2, 1, 1, 1) ? "true" : "false") << std::endl;       // Expected: false

    // 5. Empty matrix - zero dimensions
    std::vector<std::vector<int>> m_empty_0x0 = {};
    std::cout << "Target 1 in empty matrix (0x0): " << (searchMatrix(m_empty_0x0, 0, 0, 1) ? "true" : "false") << std::endl; // Expected: false

    // 6. Empty matrix - non-zero dimensions (handled by matrix.empty())
    std::vector<std::vector<int>> m_empty_1x1 = {};
    std::cout << "Target 1 in empty matrix (1x1): " << (searchMatrix(m_empty_1x1, 1, 1, 1) ? "true" : "false") << std::endl; // Expected: false

    // 7. Matrix with empty rows / non-rectangular - target found
    std::vector<std::vector<int>> m_non_rect_found = {{1,2,3}, {}, {4,5}};
    std::cout << "Target 1 in m_non_rect (3x3): " << (searchMatrix(m_non_rect_found, 3, 3, 1) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "Target 4 in m_non_rect (3x3): " << (searchMatrix(m_non_rect_found, 3, 3, 4) ? "true" : "false") << std::endl; // Expected: true

    // 8. Matrix with empty rows / non-rectangular - target not found
    std::vector<std::vector<int>> m_non_rect_not_found = {{1,2,3}, {}, {4,5}};
    std::cout << "Target 6 in m_non_rect (3x3): " << (searchMatrix(m_non_rect_not_found, 3, 3, 6) ? "true" : "false") << std::endl; // Expected: false

    // 9. Provided dimensions larger than actual matrix size (robustness test) - target found
    std::vector<std::vector<int>> m_small_found = {{1,2}, {3,4}};
    std::cout << "Target 4 in m_small (2x2 with search 3x3): " << (searchMatrix(m_small_found, 3, 3, 4) ? "true" : "false") << std::endl; // Expected: true

    // 10. Provided dimensions larger than actual matrix size (robustness test) - target not found
    std::vector<std::vector<int>> m_small_not_found = {{1,2}, {3,4}};
    std::cout << "Target 5 in m_small (2x2 with search 3x3): " << (searchMatrix(m_small_not_found, 3, 3, 5) ? "true" : "false") << std::endl; // Expected: false

    // 11. Provided dimensions smaller than actual matrix size (search only part of matrix) - target found
    std::vector<std::vector<int>> m_large_found = {{1,2,3}, {4,5,6}, {7,8,9}};
    std::cout << "Target 1 in m_large (3x3 with search 1x1): " << (searchMatrix(m_large_found, 1, 1, 1) ? "true" : "false") << std::endl; // Expected: true

    // 12. Provided dimensions smaller than actual matrix size (search only part of matrix) - target not found
    std::vector<std::vector<int>> m_large_not_found = {{1,2,3}, {4,5,6}, {7,8,9}};
    std::cout << "Target 5 in m_large (3x3 with search 1x1): " << (searchMatrix(m_large_not_found, 1, 1, 5) ? "true" : "false") << std::endl; // Expected: false

    return 0;
}