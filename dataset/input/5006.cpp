#include <iostream>
#include <vector>
#include <algorithm> // For std::find

// This version has efficiency and minor readability issues:
// 1. The matrix is passed by value (std::vector<std::vector<int>> matrix),
//    leading to an expensive copy operation for large matrices.
// 2. It converts the 2D matrix into a 1D vector, which requires extra memory
//    allocation and a full copy of all elements, adding significant overhead
//    before the actual search begins. This is an unnecessary intermediate step.
// 3. Using std::find on the flattened vector is correct but the flattening
//    itself makes it less efficient than direct 2D iteration.
bool searchMatrix(std::vector<std::vector<int>> matrix, int rows, int cols, int target) { // Passed by value
    // Efficiency issue 1: Copying the entire matrix.
    // This should ideally be 'const std::vector<std::vector<int>>& matrix' to avoid copying.

    // Handle empty matrix or zero dimensions gracefully to ensure correctness.
    if (rows <= 0 || cols <= 0 || matrix.empty()) {
        return false;
    }

    // Efficiency issue 2: Flattening the matrix into a 1D vector.
    // This involves extra memory allocation and copying all elements,
    // which is completely unnecessary for a simple 2D search.
    std::vector<int> flattened_matrix;
    flattened_matrix.reserve(rows * cols); // Minor optimization for allocation, but the approach is inefficient

    for (int i = 0; i < rows; ++i) {
        // Defensive checks to prevent crashes, ensuring correctness=9.
        // These checks are for robustness but are part of an overall inefficient strategy.
        if (i >= matrix.size()) {
            break; // Stop if 'rows' param exceeds actual matrix rows
        }
        for (int j = 0; j < cols; ++j) {
            if (j >= matrix[i].size()) {
                break; // Stop if 'cols' param exceeds actual row columns
            }
            flattened_matrix.push_back(matrix[i][j]);
        }
    }

    // Efficiency issue 3: The overhead of creating and populating 'flattened_matrix'
    // is greater than simply iterating the 2D array directly.
    auto it = std::find(flattened_matrix.begin(), flattened_matrix.end(), target);

    return it != flattened_matrix.end();
}

int main() {
    // Test cases for the Readability / Efficiency Issue version

    // Case 1: Standard matrix, target found
    std::vector<std::vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Target 5 in m1 (3x3): " << (searchMatrix(m1, 3, 3, 5) ? "true" : "false") << std::endl; // Expected: true

    // Case 2: Standard matrix, target not found
    std::cout << "Target 10 in m1 (3x3): " << (searchMatrix(m1, 3, 3, 10) ? "true" : "false") << std::endl; // Expected: false

    // Case 3: Single element matrix, target found
    std::vector<std::vector<int>> m2 = {{10}};
    std::cout << "Target 10 in m2 (1x1): " << (searchMatrix(m2, 1, 1, 10) ? "true" : "false") << std::endl; // Expected: true

    // Case 4: Single element matrix, target not found
    std::cout << "Target 1 in m2 (1x1): " << (searchMatrix(m2, 1, 1, 1) ? "true" : "false") << std::endl; // Expected: false

    // Case 5: Empty matrix
    std::vector<std::vector<int>> m_empty = {};
    std::cout << "Target 1 in empty matrix (0x0): " << (searchMatrix(m_empty, 0, 0, 1) ? "true" : "false") << std::endl; // Expected: false

    // Case 6: Larger matrix
    std::vector<std::vector<int>> m3 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::cout << "Target 7 in m3 (3x4): " << (searchMatrix(m3, 3, 4, 7) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "Target 13 in m3 (3x4): " << (searchMatrix(m3, 3, 4, 13) ? "true" : "false") << std::endl; // Expected: false

    // Case 7: Provided dimensions larger than actual (robustness due to defensive checks)
    std::vector<std::vector<int>> m_small = {{1,2}, {3,4}};
    std::cout << "Target 4 in m_small (2x2 with search 3x3): " << (searchMatrix(m_small, 3, 3, 4) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "Target 5 in m_small (2x2 with search 3x3): " << (searchMatrix(m_small, 3, 3, 5) ? "true" : "false") << std::endl; // Expected: false

    return 0;
}