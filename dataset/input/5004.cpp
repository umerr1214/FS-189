#include <vector>
#include <iostream>

// Function with a semantic error: the matrix is passed by value.
// While syntactically correct and produces the right result, it's inefficient.
bool searchMatrix(std::vector<std::vector<int>> matrix, int rows, int cols, int target) { // Semantic Error: passed by value
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows1 = 3;
    int cols1 = 3;

    std::cout << (searchMatrix(matrix1, rows1, cols1, 5) ? "true" : "false"); // Expected: true, Actual: true
    std::cout << (searchMatrix(matrix1, rows1, cols1, 10) ? "true" : "false"); // Expected: false, Actual: false
    std::cout << (searchMatrix(matrix1, rows1, cols1, 1) ? "true" : "false"); // Expected: true, Actual: true
    std::cout << (searchMatrix(matrix1, rows1, cols1, 9) ? "true" : "false"); // Expected: true, Actual: true

    // Demonstrate with a larger matrix to highlight the inefficiency
    std::vector<std::vector<int>> large_matrix(1000, std::vector<int>(1000, 0));
    if (1000 > 500 && 1000 > 500) { // Avoid potential out-of-bounds if dimensions were zero
        large_matrix[500][500] = 999;
    }
    std::cout << (searchMatrix(large_matrix, 1000, 1000, 999) ? "true" : "false"); // Expected: true, Actual: true (correct but slow)
    std::cout << (searchMatrix(large_matrix, 1000, 1000, 123) ? "true" : "false"); // Expected: false, Actual: false (correct but slow)

    return 0;
}