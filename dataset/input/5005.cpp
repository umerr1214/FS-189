#include <iostream>
#include <vector>
#include <stdexcept> // For potential out_of_range, though segfault is more likely for vector::operator[]

// This version has a robustness issue: It does not fully validate the input dimensions
// against the actual `std::vector` sizes.
// If `matrix` is empty but `rows` is passed as > 0, accessing `matrix[0]` will cause
// a runtime error (e.g., `std::out_of_range` or segmentation fault).
// Similarly, if `matrix[i]` is empty but `cols` is passed as > 0, accessing `matrix[i][0]`
// will cause a runtime error.
// The function implicitly trusts that `rows` and `cols` accurately reflect the matrix's
// dimensions and that the matrix itself is well-formed (not empty, no empty rows if `cols` > 0).
bool searchMatrix(const std::vector<std::vector<int>>& matrix, int rows, int cols, int target) {
    // Robustness issue: Missing checks for matrix.empty() if rows > 0,
    // and matrix[i].empty() if cols > 0.
    // The loops will attempt to access matrix[i][j] based purely on 'rows' and 'cols'.
    // If matrix is empty and rows > 0, matrix[0] will be an out-of-bounds access.
    // If a row matrix[i] is empty and cols > 0, matrix[i][0] will be an out-of-bounds access.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Potential runtime error here if 'i' or 'j' exceed actual vector bounds.
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Test cases for the Robustness Issue version

    // Case 1: Normal operation - target found
    std::vector<std::vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Target 5 in m1 (3x3): " << (searchMatrix(m1, 3, 3, 5) ? "true" : "false") << std::endl; // Expected: true

    // Case 2: Normal operation - target not found
    std::cout << "Target 10 in m1 (3x3): " << (searchMatrix(m1, 3, 3, 10) ? "true" : "false") << std::endl; // Expected: false

    // Case 3: Robustness issue trigger - Empty matrix, but dimensions passed as non-zero
    // This will likely cause a runtime error (e.g., segmentation fault or std::out_of_range)
    // because it tries to access matrix[0] when matrix is empty.
    std::vector<std::vector<int>> m_empty = {};
    std::cout << "Target 1 in empty matrix (1x1): " << (searchMatrix(m_empty, 1, 1, 1) ? "true" : "false") << std::endl; // Expected: false (if robust), Actual: crash

    // Case 4: Robustness issue trigger - Matrix with an empty row, but cols > 0
    // This will likely cause a runtime error when trying to access matrix[1][0]
    // because matrix[1] is an empty vector.
    std::vector<std::vector<int>> m_empty_row = {{1, 2}, {}, {3, 4}};
    std::cout << "Target 1 in m_empty_row (3x2): " << (searchMatrix(m_empty_row, 3, 2, 1) ? "true" : "false") << std::endl; // Expected: true (if robust), Actual: crash on row 1
    std::cout << "Target 5 in m_empty_row (3x2): " << (searchMatrix(m_empty_row, 3, 2, 5) ? "true" : "false") << std::endl; // Expected: false (if robust), Actual: crash on row 1

    return 0;
}