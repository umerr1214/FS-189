#include <vector>
#include <iostream>

// Function with a logical error: it only checks the first element of each row.
bool searchMatrix(std::vector<std::vector<int>>& matrix, int rows, int cols, int target) {
    for (int i = 0; i < rows; ++i) {
        // Logical Error: Only checks the element at column 0 for each row.
        // It should iterate through all columns (j) in an inner loop.
        if (cols > 0 && matrix[i][0] == target) { // This condition is the error
            return true;
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

    std::cout << (searchMatrix(matrix1, rows1, cols1, 5) ? "true" : "false"); // Expected: true, Actual: false (Logical Error)
    std::cout << (searchMatrix(matrix1, rows1, cols1, 10) ? "true" : "false"); // Expected: false, Actual: false
    std::cout << (searchMatrix(matrix1, rows1, cols1, 1) ? "true" : "false"); // Expected: true, Actual: true
    std::cout << (searchMatrix(matrix1, rows1, cols1, 9) ? "true" : "false"); // Expected: true, Actual: false (Logical Error)

    std::vector<std::vector<int>> matrix2 = {{10,11,12,13},{14,15,16,17}};
    int rows2 = 2;
    int cols2 = 4;
    std::cout << (searchMatrix(matrix2, rows2, cols2, 11) ? "true" : "false"); // Expected: true, Actual: false (Logical Error)
    std::cout << (searchMatrix(matrix2, rows2, cols2, 14) ? "true" : "false"); // Expected: true, Actual: true

    return 0;
}