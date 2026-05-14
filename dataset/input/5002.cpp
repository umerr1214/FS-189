#include <vector>
#include <iostream>

// Function definition with a syntax error: missing semicolon after return true
bool searchMatrix(std::vector<std::vector<int>>& matrix, int rows, int cols, int target) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == target) {
                return true // Syntax Error: Missing semicolon here
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

    // The program will not compile due to the syntax error.
    // The following lines are for demonstration of intended usage.
    // std::cout << "Target 5 found: " << (searchMatrix(matrix1, rows1, cols1, 5) ? "true" : "false") << std::endl;
    // std::cout << "Target 10 found: " << (searchMatrix(matrix1, rows1, cols1, 10) ? "true" : "false") << std::endl;

    return 0;
}